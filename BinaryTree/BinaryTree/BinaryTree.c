#define _CRT_SECURE_NO_WARNINGS
#include"BinaryTree.h"
#include"Queue.h"
BTNode* CreatNode(int n)
{
	BTNode* a = (BTNode*)malloc(sizeof(BTNode));
	if (a == NULL)
	{
		perror("malloc");
		return NULL;
	}
	a->data = n;
	a->left = a->right = NULL;
	return a;
}
//����
//BTNode* BinaryTreeCreate()
//{
//	BTNode* node1 = CreatNode(1);
//	BTNode* node2 = CreatNode(2);
//	BTNode* node3 = CreatNode(3);
//	BTNode* node4 = CreatNode(4);
//	BTNode* node5 = CreatNode(5);
//	BTNode* node6 = CreatNode(6);
//	
//	node1->left = node2;
//	node1->right = node4;
//	node2->left = node3;
//	node4->left = node5;
//	node4->right = node6;
//	return node1;
//}
// ͨ��ǰ�����������"abd##e#h##cf##g##"����������
BTNode* BinaryTreeCreate(BTDataType* a,int* pi)
{
	if (a[(*pi)] == '#')
	{
		(*pi)++;
		return NULL;
	}
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (root == NULL)
	{
		perror("malloc");
		return NULL;
	}
	root->data = a[(*pi)++];
	root->left = BinaryTreeCreate(a, pi);
	root->right = BinaryTreeCreate(a, pi);
	return root;
}
// 二叉树前序遍历 
void BTPrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("#");
		return;
	}
	printf("%c", root->data);
	BTPrevOrder(root->left);
	BTPrevOrder(root->right);
}
// 二叉树中序遍历
void BTInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	BTInOrder(root->left);
	printf("%c ", root->data);
	BTInOrder(root->right);
}
// 二叉树后序遍历
void BTPostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	BTPostOrder(root->left);
	BTPostOrder(root->right);
	printf("%c ", root->data);

}
// 二叉树节点个数
int TreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return TreeSize(root->left) +
		TreeSize(root->right) + 1;
}
// 二叉树叶子节点个数
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}
int my_max(int x, int y)
{
	return x > y ? x : y;
}
//二叉树的高度
int TreeHeight(BTNode* root)
{
	
	if (root == NULL)
	{
		return 0;
	}
	return my_max(TreeHeight(root->left), TreeHeight(root->right)) + 1;
}
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
	{
		return root;
	}
	BTNode* s1 = BinaryTreeFind(root->left, x);
	if (s1)
	{
		return s1;
	}
	BTNode* s2 = BinaryTreeFind(root->right, x);
	if (s2)
	{
		return s2;
	}
	return NULL;
}
void BinaryTreeDestory(BTNode* root)
{ 
	if (root == NULL)
	{
		return;
	}
	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
}
void TreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		printf("%c ", front->data);
		QueuePop(&q);

		if (front->left)
		{
			QueuePush(&q, front->left);
		}
		if (front->right)
		{
			QueuePush(&q, front->right);
		}
	}
	QueueDestroy(&q);
}
bool BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front->data != '#')
		{
			if (front->left)
			{
				QueuePush(&q, front->left);
			}
			if (front->right)
			{
				QueuePush(&q, front->right);
			}
		}
		else
		{
			if (front->data != '#')
			{
				return false;
			}
		}
	}
	return true;

	QueueDestroy(&q);
}
