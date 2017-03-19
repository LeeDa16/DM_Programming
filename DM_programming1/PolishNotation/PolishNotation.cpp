#include "PolishNotation.h"

void getString(string & s)
{
	ifstream fstrm("PolishNotation_InPut.txt");
	getline(fstrm, s);
	
	/*
	cout << "请输入一条中缀表达式：" << endl;
	while (true)
	{
		if(getline(cin, s) != 0)
		{
			string tmp = "";
			for (auto c : s)
			{
				if (!isspace(c))
				{
					tmp += c;
				}
			}
			s = tmp;
			if (examine(s) == 1)
			{
				break;
			}
		}
		else
		{
			cout << endl;
			cout << "输入表达式有误，请重新输入：" << endl;
		}
	}*/
}

int examine(string s)
{
	int isInBracket = 0;
	int flag = 0;
	if (s[0] == ')' || s[0] == '!' || s[0] == '&' || s[0] == '|' || s[0] == '^' || s[0] == '~')
	{
		return 0;
	}
	for (unsigned i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			isInBracket++;
		}
		else if (s[i] == ')')
		{
			if (s[i - 1] == '(')
			{
				return 0;
			}
			isInBracket--;
		}
		else if ((s[i] == '!' || s[i] == '&' || s[i] == '|' || s[i] == '^' || s[i] == '~'))
		{
			if (flag != 1)
			{
				flag = 1;
			}
			else if (s[i] != '!' || s[i - 1] == '(')
			{
				return 0;
			}
		}
		else
		{
			if (flag != -1)
			{
				flag = -1;
			}
			else
			{
				return 0;
			}
		}
	}
	if (isInBracket != 0 || flag == 1)
	{
		return 0;
	}
	return 1;
}

int priority(char c)
{
	switch (c)
	{
	case '&':
		return 1;
	case'|':
		return 2;
	case'^':
		return 3;
	case'~':
		return 4;
	default:
		return -1;
	}
}

int search(string s, int begin, int end)
{
	int tag = -1;
	int isInBracket = 0;

	if (s[begin] == '(' && s[end] == ')')
	{
		begin++;
		end--;
	}

	int prior = 0;

	for (int i = begin; i < end; i++)
	{
		if (s[i] == '(')
		{
			isInBracket++;
		}

		else if (s[i] == ')')
		{
			isInBracket--;
		}

		if (priority(s[i]) > prior && isInBracket == 0)
		{
			tag = i;
			prior = priority(s[i]);
		}
	}

	if (prior == 0)
	{
		tag = begin;
	}

	return tag;
}

struct BiTNode *CreateBiTree(string s, int begin, int end)
{
	struct BiTNode *p = NULL;

	if (begin == end)
	{
		p = (struct BiTNode *)malloc(sizeof(struct BiTNode));

		p->key = s[begin];
		p->lchild = p->rchild = NULL;
	}
	else
	{
		int tag = search(s, begin, end);
		p = (struct BiTNode *)malloc(sizeof(struct BiTNode));

		p->key = s[tag];

		if (tag == begin)
		{
			p->lchild = CreateBiTree(s, begin + 1, end);
			p->rchild = NULL;
		}
		else
		{
			if (s[begin] == '(' && s[end] == ')')
			{
				begin++;
				end--;
			}

			p->lchild = CreateBiTree(s, begin, tag - 1);
			p->rchild = CreateBiTree(s, tag + 1, end);
		}
	}

	return p;
}

void outPutPNotation(struct BiTNode *head)
{
	if (head != NULL)
	{
		cout << head->key;
		outPutPNotation(head->lchild);
		outPutPNotation(head->rchild);
	}
}

void  outPutReversePNotation(BiTNode * head)
{
	if (head != NULL)
	{
		outPutReversePNotation(head->lchild);
		outPutReversePNotation(head->rchild);
		cout << head->key;
	}
}
