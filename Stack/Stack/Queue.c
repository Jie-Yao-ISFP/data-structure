#define _CRT_SECURE_NO_WARNINGS
#include"Queue.h"
// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);
	q->phead = q->ptail = NULL;
	q->size = 0;
}
// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	newnode->data = data;
	newnode->next = NULL;
	if (q->phead == NULL)//栈为空
	{
		q->phead = q->ptail = newnode;
	}
	else
	{
		q->ptail->next = newnode;
		q->ptail = newnode;
	}
	q->size++;
}
// 队头出队列 
void QueuePop(Queue* q)//头删
{
	assert(q);
	assert(q->size);
	if (q->phead == q->ptail)//只有一个元素
	{
		free(q->phead);
		q->phead = q->ptail = NULL;
	}
	else//多个元素
	{
		QNode* next = q->phead->next;
		free(q->phead);
		q->phead = next;
	}
	q->size--;
}
// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->phead);
	return q->phead->data;
}
// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->ptail);
	return q->ptail->data;
}
// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	assert(q);
	return q->size;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->size == 0;
}
// 销毁队列 
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* cur = q->phead;
	while (cur != NULL)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	q->phead = q->ptail = NULL;
	q->size = 0;
}