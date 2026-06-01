#define _CRT_SECURE_NO_WARNINGS
#include"stack.h"
int main()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	return 0;
}