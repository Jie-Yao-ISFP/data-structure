#define _CRT_SECURE_NO_WARNINGS
#include"Heap.h"
void Test1()
{
	int arr[] = { 1,2,3,7,8,9,6,5,4 };
	Heap hp;
	HeapInit(&hp);
	int size = sizeof(arr) / sizeof(HPDataType);
	for (int i = 0; i < size; i++)
	{
		HeapPush(&hp, arr[i]);
	}
	for (int i = 0; i < size; i++)
	{
		printf("%d ", hp.a[i]);
	}
	HeapDestory(&hp);
}
void Test2()
{
	int arr[] = { 1,2,3,7,8,9,6,5,4 };
	int size = sizeof(arr) / sizeof(int);
	printf("ÅÅÐòÇ°");
	for (int i = 0; i <size; i++)
	{
		printf("%d ", arr[i]);
	}
	HeapSort(arr, size);
	printf("\nÅÅÐòºó");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}
void Test3()
{
	printf("ÇëÊäÈëk:");
	int k = 0;
	scanf("%d", &k);
	PrintTopK(k);
}
int main()
{
	//Test2();
	//Test1();
	Test3();
	return 0;
}