#define _CRT_SECURE_NO_WARNINGS
#include"DSLT.h"
//创建结点
LTNode* BuyNode(LTDataType x)
{
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	if (phead == NULL)
	{
		exit(1);
	}
	phead->data = x;
	phead->next = phead->prev = phead;
	return phead;
}
//创建哨兵位
LTNode* LTInit()
{
	LTNode* phead = BuyNode(-1);
	return phead;
}
//尾插
void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = BuyNode(x);
	if (newnode == NULL)
	{
		perror("malloc");
		exit(1);
	}
	//phead newnode phead->prev
	newnode->prev = phead->prev;
	newnode->next = phead;
	phead->prev->next = newnode;
	phead->prev = newnode;
}
//打印
void LTPrint(LTNode* phead)
{
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("\n");
}
//头插
void LTPushFront(LTNode* phead, LTDataType x)
{
	LTNode* newnode = BuyNode(x);
	//改变phead newnode phead的下一个结点
	newnode->prev = phead;
	newnode->next = phead->next;
	phead->next = newnode;
	newnode->next->prev = newnode;//通过newnode找
}
//尾删
void LTPopBack(LTNode* phead)
{
	assert(phead && phead->next != phead);
	LTNode* del = phead->prev;
	phead->prev = del->prev;
	del->prev->next = del->next;
	free(del);
	del = NULL;
}
//头删
void LTPopFront(LTNode* phead)
{
	assert(phead && phead->next != phead);
	LTNode* del = phead->next;
	phead->next = del->next;
	del->next->prev = del->prev;
	free(del);
	del = NULL;
}
//查找节点
LTNode* LTFind(LTNode* phead, LTDataType x)
{
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	//没找到
	printf("没找到");
	return NULL;
}
//在pos后插入数据
void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newnode = BuyNode(x);
	//newnode pos pos->next
	newnode->next = pos->next;
	newnode->prev = pos;
	pos->next = newnode;
	newnode->next->prev = newnode;
}
//删除pos节点
void LTErase(LTNode* pos)
{
	//pos->prev pos->next
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;

}
//销毁链表
void LTDestory(LTNode* phead)
{
	LTNode* pcur = phead->next;
	while (pcur != NULL)
	{
		LTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	free(phead);
	phead = NULL;
}