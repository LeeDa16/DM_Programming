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
	cout << "波兰表达式为：" << endl;
	outPutPNotation(p);
	cout << endl;

	cout << endl;
	cout << "逆波兰表达式为：" << endl;
	outPutReversePNotation(p);

	cout << endl;
	cout << endl;
	
	return 0;
}
