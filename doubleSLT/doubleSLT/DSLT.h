#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int LTDataType;
struct LTNode
{
	LTDataType data;
	struct LTNode* prev;
	struct LTNode* next;
};
typedef struct LTNode LTNode;
//创建结点
LTNode* BuyNode(LTDataType x);
//初始化
LTNode* LTInit();
//尾插
void LTPushBack(LTNode* phead, LTDataType x);
//打印
void LTPrint(LTNode* phead);
//头插
void LTPushFront(LTNode* phead, LTDataType x);
//尾删
void LTPopBack(LTNode* phead);
//头删
void LTPopFront(LTNode* phead);
//查找节点
LTNode* LTFind(LTNode* phead, LTDataType x);
//在pos后插入数据
void LTInsert(LTNode* pos, LTDataType x);
//删除pos节点
void LTErase(LTNode* pos);
//销毁链表
void LTDestory(LTNode* phead);
