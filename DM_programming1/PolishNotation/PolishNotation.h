#ifndef POLISHNOTATION_H
#define POLISHNOTATION_H

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct BiTNode
{
	char key;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
};

extern void getString(string &s);
extern int examine(string s);
extern int priority(char c);
extern int search(string s, int begin, int end);
extern struct BiTNode *CreateBiTree(string s, int begin, int end);
extern void outPutPNotation(struct BiTNode *head);
extern void outPutReversePNotation(struct BiTNode *head);

#endif // !POLISHNOTATION_H
