#define _CRT_SECURE_NO_WARNINGS
#include"stack.h"
// 初始化栈 
void StackInit(Stack* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;//top指向栈顶的下一个元素(top=元素个数)
	ps->capacity = 0;
}
// 入栈 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4: 2 * ps->capacity;
		//栈为空时放入四个字节的空间,栈不为空时按2倍扩容
		STDataType* tem = (STDataType*)realloc(ps->a, newcapacity * sizeof(STDataType));
		if (tem == NULL)
		{
			perror("realloc");
			return;
		}
		ps->a = tem;
		ps->capacity = newcapacity;
	}
	ps->a[ps->top] = data;
	ps->top++;
}
// 出栈 
void StackPop(Stack* ps)
{
	assert(ps);
	ps->top--;
}
// 获取栈顶元素 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	int ret = ps->a[ps->top - 1];
	return ret;
}
// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	asssert(ps);
	return ps->top == 0;
}
// 销毁栈 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}