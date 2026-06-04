#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;
// 通过前序遍历的字符串"abd##e#h##cf##g##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int* pi);
// 二叉树的销毁
void BinaryTreeDestory(BTNode* root);
// 二叉树节点个数
int TreeSize(BTNode* root);
// 二叉树叶子节点个数
int TreeLeafSize(BTNode* root);
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k);
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// 二叉树前序遍历 
void BTPrevOrder(BTNode* root);
// 二叉树中序遍历
void BTInOrder(BTNode* root);
// 二叉树后序遍历
void BTPostOrder(BTNode* root);
// 层序遍历
void TreeLevelOrder(BTNode* root);
// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTNode* root);
//二叉树的高度
int TreeHeight(BTNode* root);
