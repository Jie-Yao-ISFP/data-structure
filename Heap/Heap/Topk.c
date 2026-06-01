#define _CRT_SECURE_NO_WARNINGS
#include"Heap.h"
#include<time.h>
void CreateNDate()
{
	// 造数据
	int n = 10000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (size_t i = 0; i < n; ++i)
	{
		int x = rand() % 1000000;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}
void PrintTopK(int k)
{
	//CreateNDate();
	int* kminheap = (int*)malloc(k * sizeof(int));
	if (kminheap == NULL)
	{
		perror("malloc fail");
		return;
	}
	const char* file = "data.txt";
	FILE* fin = fopen(file, "r");
	for (int i = 0; i < k; i++)
	{
		fscanf(fin, "%d", &kminheap[i]);
	}//找出前十个数据放在小堆里
	for (int i = (k - 1 - 1) / 2; i < k; i++)
	{
		AdjustDown(kminheap, i, k);
	}//建堆
	int tem = 0;
	while (fscanf(fin, "%d", &tem) > 0)//将文件中的数据读取到tem里
	{
		if (tem > kminheap[0])//大的数入堆
		{
			kminheap[0] = tem;
			AdjustDown(kminheap, 0, k);
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d ", kminheap[i]);
	}
}