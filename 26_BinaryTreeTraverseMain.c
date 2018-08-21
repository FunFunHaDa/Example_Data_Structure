#include<stdio.h>
#include "26_BinaryTree.h"

void InorderTraverse(BTreeNode * bt)
{
	if (bt == NULL)	// bt¸é Àç±Í Å»Ãâ
		return;

	InorderTraverse(bt->left);
	printf("%d \n", bt->data);
	InorderTraverse(bt->right);
}

int main(void)
{
	BTreeNode * bt1 = MakeBtreeNode();
	BTreeNode * bt2 = MakeBtreeNode();
	BTreeNode * bt3 = MakeBtreeNode();
	BTreeNode * bt4 = MakeBtreeNode();

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);

	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);

	InorderTraverse(bt1);
	return 0;
}