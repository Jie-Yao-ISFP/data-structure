#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;//创建结构体类型
//创建空间
SLTNode* Buynewnode(SLTDataType x);
void SLTPrint(SLTNode* plist);//打印

void SLTPushBack(SLTNode** pphead, SLTDataType x);//尾插

void SLTPushFront(SLTNode** pphead, SLTDataType x);//头插

void SLTPopFront(SLTNode** pphead);//头删

void SLTPopBack(SLTNode** pphead);//尾删

SLTNode* SLTFind(SLTNode* phead, SLTDataType x);//查找

void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);//在指定位置之前插入数据

void SLTInsertAfter(SLTNode* pos, SLTDataType x);//在指定位置之后插入数据

void SLTErase(SLTNode** pphead, SLTNode* pos);//删除pos节点

void SLTEraseAfter(SLTNode** pphead, SLTNode* pos);//删除pos后一个节点

void SListDesTroy(SLTNode** pphead);//销毁链表