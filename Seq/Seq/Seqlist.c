#define _CRT_SECURE_NO_WARNINGS
#include"Seqlist.h"
void Seqliststart(SL* sl)//初始化
{
	sl->arr = NULL;
	sl->capacity = 0;
	sl->size = 0;
}
void SeqCheck(SL* sl)//检测,扩容
{
	assert(sl);
	if (sl->size == sl->capacity)
	{
		int newcapacity = sl->capacity;
		newcapacity = sl->capacity == 0 ? sizeof(Seqdatatype) : 2 * sl->capacity;
		Seqdatatype* tmp = sl->arr;
		tmp = (Seqdatatype*)realloc(sl->arr, newcapacity * sizeof(Seqdatatype));
		if (tmp == NULL)
		{
			perror("realloc");
			exit(1);
		}
		sl->arr = tmp;
		sl->capacity = newcapacity;
	}
}
void Seqpush_back(SL* sl, int data)//尾插
{
	SeqCheck(sl);
	sl->arr[sl->size] = data;
	sl->size++;
}
void SeqlistPrint(SL sl)//打印
{
	for (int i = 0; i < sl.size; i++)
	{
		printf("%d ", sl.arr[i]);
	}
	printf("\n");
}
void Seqpush_front(SL* sl, int data)//头插
{
	SeqCheck(sl);
	for (int i = sl->size; i > 0; i--)
	{
		sl->arr[i] = sl->arr[i - 1];
	}
	sl->arr[0] = data;
	sl->size++;
}
void Seqpop_back(SL* sl)//尾删
{
	SeqCheck(sl);
	assert(sl->size);
	sl->size--;//有效数字减少,在增删查改操作中均能体现尾删的效果
}
void Seqpop_front(SL* sl)//头删
{
	SeqCheck(sl);
	assert(sl->size);
	for (int i = 0;i<sl->size-1; i++)//0 1 2 3 size(size=4)
	{
		sl->arr[i] = sl->arr[i + 1]; 
	}
	sl->size--;
}
void Seqdestroy(SL* sl)//顺序表销毁
{
	SeqCheck(sl);
	sl->size = 0;
	sl->capacity = 0;
	if (sl->arr != NULL)
	{
		free(sl->arr);
		sl = NULL;
	}
	
}
//查找
int SLFind(SL* sl, Seqdatatype x)
{
	assert(sl);
	for (int i = 0;i<sl->capacity; i++)
	{
		if (sl->arr[i] == x)
		{
			return i;
		}
	}
	printf("没找到");
}
//指定位置之前插入
void SeqInsert(SL* sl, int pos, Seqdatatype x)
{
	assert(sl);
	sl->capacity++;
	SeqCheck(sl);
	for (int i = sl->capacity; i > pos; i--)
	{
		sl->arr[i] = sl->arr[i - 1];
	}
	sl->arr[pos] = x;
}
//指定位置删除数据
void SeqErase(SL* ps, int pos)
{
	assert(ps);
	for (int i = pos; i < ps->capacity; i++)
	{
		ps->arr[i] = ps->arr[i + 1];

	}
}