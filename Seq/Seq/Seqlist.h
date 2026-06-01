#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int Seqdatatype;
struct Seqlist
{
	Seqdatatype* arr;
	int size;//有效数据个数
	int capacity;//空间大小
}sl;

typedef struct Seqlist SL;

void Seqliststart(SL* sl);//初始化

void SeqCheck(SL* sl);//检查顺序表
//尾插
void Seqpush_back(SL* sl, int data);
//头插
void Seqpush_front(SL* sl, int data);
//尾删
void Seqpop_back(SL* sl);
//头删
void Seqpop_front(SL* sl);
//打印
void SeqlistPrint(SL sl);
//顺序标的销毁
void Seqdestroy(SL* sl);
//查找
int SLFind(SL* sl, Seqdatatype x);
//指定位置之前插入
void SeqInsert(SL* sl, int pos, Seqdatatype x);
//指定位置删除数据
void SeqErase(SL* ps,int pos);

