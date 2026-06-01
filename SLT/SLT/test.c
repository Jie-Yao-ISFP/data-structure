#define _CRT_SECURE_NO_WARNINGS
#include"SLTlist.h"
void test01()
{
	SLTNode* plist = NULL;
	SLTPushFront(&plist, 4);
	//SLTPushBack(&plist, 1);
	SLTPushFront(&plist, 3);
	SLTPushFront(&plist, 2);
	SLTPushFront(&plist, 1);
	//SLTPushBack(&plist, 3);
	//SLTPushBack(&plist, 5);
	SLTPrint(plist);
	//SLTPopBack(&plist);//尾删
	//SLTPrint(plist);
	//SLTPopFront(&plist);//头删
	//SLTPrint(plist);
	SLTNode* find = SLTFind(plist,1);
	//SLTInsert(&plist, find, 3);
	//SLTPrint(plist);
	//SLTNode* find2 = SLTFind(plist, 4);
	//SLTInsertAfter(find2, 12);
	//SLTPrint(plist);
	SLTEraseAfter(&plist, find);
	SLTPrint(plist);
	SListDesTroy(&plist);
}

int main()
{
	test01();
	return 0;
}