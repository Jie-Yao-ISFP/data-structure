#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;//大小
	int capacity;//容量
}Heap;

void HeapInit(Heap* php);
// 堆的销毁
void HeapDestory(Heap* hp);
// 堆的插入
void HeapPush(Heap* hp, HPDataType x);
// 堆的删除
void HeapPop(Heap* hp);
// 取堆顶的数据
HPDataType HeapTop(Heap* hp);
// 堆的数据个数
int HeapSize(Heap* hp);
// 堆的判空
int HeapEmpty(Heap* hp);
void AdjustUp(HPDataType* a, int child);//向上调整
void Swap(HPDataType* a, HPDataType* b);//交换
void AdjustDown(HPDataType* a, int parent, int size);
// 对数组进行堆排序
void HeapSort(int* a, int n);
//Topk问题
void PrintTopK(int k);
void CreateNDate();