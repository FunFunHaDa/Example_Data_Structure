#include<stdio.h>
#include "12_BinarySearchTree.h"

int main(void)
{
	BTreeNode * bstRoot;
	BTreeNode * sNode;

	BSTMakeAntInit(&bstRoot);

	BSTInsert(&bstRoot, 9);
	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 6);
	BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 8);
	BSTInsert(&bstRoot, 3);
	BSTInsert(&bstRoot, 5);

	sNode = BSTSearch(bstRoot, 1);
	if (sNode == NULL)
		printf("Å½»ö ½ÇÆÐ \n");
	else
		printf("Å¸°Ù ÀúÀå ÀÎµ¦½º:  %d \n", BSTGetNodeData(sNode));
	sNode = BSTSearch(bstRoot, 4);
	if (sNode == NULL)
		printf("Å½»ö ½ÇÆÐ \n");
	else
		printf("Å¸°Ù ÀúÀå ÀÎµ¦½º:  %d \n", BSTGetNodeData(sNode));
	sNode = BSTSearch(bstRoot, 6);
	if (sNode == NULL)
		printf("Å½»ö ½ÇÆÐ \n");
	else
		printf("Å¸°Ù ÀúÀå ÀÎµ¦½º:  %d \n", BSTGetNodeData(sNode));
	sNode = BSTSearch(bstRoot, 7);
	if (sNode == NULL)
		printf("Å½»ö ½ÇÆÐ \n");
	else
		printf("Å¸°Ù ÀúÀå ÀÎµ¦½º:  %d \n", BSTGetNodeData(sNode));
	return 0;
}