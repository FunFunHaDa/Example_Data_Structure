#include<stdio.h>
#include<stdlib.h>
#include "9_BinaryTree2.h"

BTreeNode * MakeBTreeNode(void)
{
	BTreeNode * nd = (BTreeNode *)malloc(sizeof(BTreeNode));
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

BTData GetData(BTreeNode * bt)
{
	return bt->data;
}

void SetData(BTreeNode * bt, BTData data)
{
	bt->data = data;
}

BTreeNode * GetLeftSubTree(BTreeNode * bt)
{
	return bt->left;
}

BTreeNode * GetRightSubTree(BTreeNode * bt)
{
	return bt->right;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{
	if (main->left != NULL)
		free(main->left);
	main->left = sub;
}

void MakeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
	if (main->right != NULL)
		free(main->right);
	main->right = sub;
}

void PreorederTraverse(BTreeNode * bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;

	action(bt->data);
	PreorederTraverse(bt->left, action);
	PreorederTraverse(bt->right, action);
}

void InorederTraverse(BTreeNode * bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;

	InorederTraverse(bt->left, action);
	action(bt->data);
	InorederTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;

	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);
}