#define _CRT_SECURE_NO_WARNINGS
#include"SLTlist.h"
SLTNode* Buynewnode(SLTDataType x)//创建空间
{
	SLTNode* plist = (SLTNode*)malloc(sizeof(SLTNode));
	if (plist == NULL)
	{
		perror("malloc");
		exit(1);
	}
	else
	{
		plist->data = x;
		plist->next = NULL;
		return plist;
	}
	
}
//打印
void SLTPrint(SLTNode* plist)
{
	assert(plist);
	while (plist)
	{
		printf("%d->", plist->data);
		plist = plist->next;
	}
	printf("NULL\n");
}
//尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* ptail = *pphead;
	SLTNode* newnode = Buynewnode(x);
	if ((*pphead) == NULL)
	{
		(*pphead)= newnode;
	}
	else
	{
		while (ptail->next)//=ptail->next!=NULL
		{
			ptail = ptail->next;
		}//找尾
		//ptail->next=NULL
		ptail->next = newnode;//将newnode作为最后一个节点
	}

}
//头插
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = Buynewnode(x);
	SLTNode* old_head = *pphead;//old_head指向第一个节点
	newnode->next = old_head;//newnode将old_head作为自己的下一个节点,所以newnode变为了第一个节点
	*pphead = newnode;

}
//头删
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && *pphead);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}
//尾删
void SLTPopBack(SLTNode** pphead)
{
	//假如只有一个节点
	if ((*pphead)->next==NULL)//*pphead==NULL
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode cur;
		cur.next = *pphead;
		SLTNode* pcur = cur.next;
		SLTNode* secptail = *pphead;
		while (pcur->next != NULL)
		{
			secptail = pcur;
			pcur = pcur->next;
		}//找到最后一个节点和倒数第二个节点
		secptail->next = NULL;
		free(pcur);
		pcur = NULL;
	}
}
//查找
SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	assert(phead);
	SLTNode* pcur = phead;
	while (pcur->data != x)
	{
		pcur = pcur->next;
	}
	if (pcur != NULL)
	{
		//printf("找到了!\n");
	}
	else
		printf("没找到!\n");
	return pcur;
}
//在指定位置前插入元素
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)//pos是要插入的位置
{
	assert(*pphead && pphead);
	assert(pos);
	SLTNode* newnode = Buynewnode(x);//创建插入的链表
	SLTNode* prev = *pphead;
	if (pos == *pphead)
	{
		SLTPushFront(pphead, x);
	}

	else
	{
		while (prev->next != pos)
		{
			prev = prev->next;
		}//找到pos的前一个节点
		newnode->next = prev->next;
		prev->next = newnode;
	}
}
//在指定位置之后插入数据
void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = Buynewnode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
void SLTErase(SLTNode** pphead, SLTNode* pos)//删除pos节点
{
	assert(*pphead && pos);
	SLTNode* prev = *pphead;
	if (pos == *pphead)//pos是头结点
	{
		SLTPopFront(pphead);
	}
	else//pos不是头结点
	{
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}
void SLTEraseAfter(SLTNode** pphead, SLTNode* pos)//删除pos后一个节点
{
	assert(pos && *pphead&&pos->next);
	SLTNode* prev = pos->next;
	pos->next = pos->next->next;
	free(prev);
	prev = NULL;
}
void SListDesTroy(SLTNode** pphead)
{
	assert(*pphead && pphead);
	SLTNode* next = NULL;
	SLTNode* pcur = *pphead;
	while (*pphead != NULL)
	{
		next = (*pphead)->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}