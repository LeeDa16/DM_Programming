#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

#include "PolishNotation.h"

int main()
{
	string s;
	getString(s);
	int len = s.size();
	
	struct BiTNode *p = CreateBiTree(s, 0, len - 1);

	cout << endl;
	cout << "�������ʽΪ��" << endl;
	outPutPNotation(p);
	cout << endl;

	cout << endl;
	cout << "�沨�����ʽΪ��" << endl;
	outPutReversePNotation(p);

	cout << endl;
	cout << endl;
	
	return 0;
}
