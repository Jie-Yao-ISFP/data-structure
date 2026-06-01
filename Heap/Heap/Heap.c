#define _CRT_SECURE_NO_WARNINGS
#include"Heap.h"
void HeapInit(Heap* php)//堆的初始化
{
	assert(php);
	php->a = NULL;
	php->capacity = 0;
	php->size = 0;
}
void Swap(HPDataType* a, HPDataType* b)
{
	HPDataType tmp = *a;
	*a = *b;
	*b = tmp;
}
void AdjustUp(HPDataType* a, int child)//向上调整
{
	while (child > 0)
	{
		int parent = (child-1) / 2;
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
		}
		else
			break;
	}
}
// 堆的插入
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->size == hp->capacity)
	{
		int newcapacity = hp->capacity == 0 ? 4 : hp->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(hp->a,sizeof(HPDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc");
			exit(1);
		}
		hp->a = tmp;
		hp->capacity = newcapacity;
	}//扩容
	hp->a[hp->size] = x;
	hp->size++;
	//准备调整堆
	AdjustUp(hp->a, hp->size-1);
}
void AdjustDown(HPDataType* a, int parent,int size)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child] > a[child + 1])
		{
			child += 1;
		}//挑出两个孩子中较小的那个
		if (a[parent] > a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void HeapPop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	Swap(&hp->a[hp->size - 1], &hp->a[0]);
	hp->size--;//删掉被挪到最后的根元素
	AdjustDown(hp->a, 0, hp->size);
}
// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->a[0];
}
// 堆的数据个数
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}
// 堆的判空
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->size == 0;
}
// 堆的销毁
void HeapDestory(Heap* hp)
{
	free(hp->a);
	hp->a = 0;
	hp->capacity = hp->size = 0;
}
// 对数组进行堆排序
void HeapSort(int* a, int n)
{
	//升序建大堆
	//降序建小堆


	//for (int i = 1; i < n; i++)
	//{
	//	AdjustUp(a, i);
	//}//向上调整建堆(O(N*logN))
	for (int i = (n-1-1)/2;i<n;i++)
	{
		AdjustDown(a, i, n);
	}//向下调整建堆(O(N))
	int end = n;
	while (end > 0)
	{
		Swap(&a[0], &a[end - 1]);//把堆顶的数据拿到堆底，然后--end，这个数据放在这里就不动了
		end--;
		AdjustDown(a, 0, end);//将放上去的数据再根据堆的规则拿下来
		
	}
}