#include<stdio.h>
#include "BinaryTree3.h"

// LLȸ��
BTreeNode * RotateLL(BTreeNode * bst)	
{
	BTreeNode * pNode;	// parent node
	BTreeNode * cNode;	// child node

	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	ChangeLeftSubTree(pNode, GEtRightSubTree(cNode));
	ChangeRightSubTree(pNode, pNode);

	return cNode;
}

// RRȸ��
BTreeNode * RotateRR(BTreeNode * bst)
{
	BTreeNode * pNode;
	BTreeNode * cNode;

	pNode = bst;
	cNode = GEtRightSubTree(pNode);

	ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
	ChangeLeftSubTree(cNode, pNode);

	return cNode;
}

// RLȸ��
BTreeNode * RotateRL(BTreeNode * bst)
{
	BTreeNode * pNode;
	BTreeNode * cNode;

	pNode = bst;
	cNode = GEtRightSubTree(pNode);

	ChangeRightSubTree(pNode, RotateLL(cNode));
	return RotateRR(pNode);
}

// LRȸ��
BTreeNode * RotateLR(BTreeNode * bst)
{
	BTreeNode * pNode;
	BTreeNode * cNode;

	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	ChangeLeftSubTree(pNode, RotateRR(cNode));
	return RotateLL(pNode);
} 

// Ʈ���� ���̸� ����Ͽ� ��ȯ
int GetHeight(BTreeNode * bst)
{
	int leftH;
	int rightH;

	if (bst == NULL)
		return 0;

	leftH = GetHeight(GetLeftSubTree(bst));
	rightH = GetHeight(GEtRightSubTree(bst));

	if (leftH > rightH)
		return leftH + 1;
	else
		return rightH + 1;
}

// �� ���� Ʈ���� ������ ���� ��ȯ
int GetHeightDiff(BTreeNode * bst)
{
	int lsh;
	int rsh;

	if (bst == NULL)
		return 0;
	lsh = GetHeight(GetLeftSubTree(bst));
	rsh = GetHeight(GEtRightSubTree(bst));
	return lsh - rsh;
}

// Ʈ���� ������ ��´�.
BTreeNode * Rebalance(BTreeNode ** pRoot)
{
	int hDiff = GetHeightDiff(*pRoot);

	if (hDiff > 1)
	{
		if (GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)
			*pRoot = RotateLL(*pRoot);
		else
			*pRoot = RotateLR(*pRoot);
	}

	if (hDiff < -1)
	{
		if (GetHeightDiff(GEtRightSubTree(*pRoot)) < 0)
			*pRoot = RotateRR(*pRoot);
		else
			*pRoot = RotateRL(*pRoot);
	}
	return *pRoot;
}