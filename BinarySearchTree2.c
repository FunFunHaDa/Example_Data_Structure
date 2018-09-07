#include<stdio.h>
#include<stdlib.h>
#include"BinaryTree3.h"
#include "BinarySearchTree2.h"

// ���� Ž�� Ʈ���� ���� �� �ʱ�ȭ
void BSTMakeAndInit(BTreeNode ** pRoot)
{
	*pRoot = NULL;
}

// ��忡 ����� ������ ��ȯ
BSTData BSTGetNodeData(BTreeNode * bst)
{
	return GetData(bst);
}

// ���� Ž�� Ʈ���� ������� ������ ����
void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
	BTreeNode * pNode = NULL; // parent node
	BTreeNode * cNode = *pRoot; // current node
	BTreeNode * nNode = NULL;	// new Node

	while (cNode != NULL)
	{
		if (data == GetData(cNode))
			return;
		pNode = cNode;

		if (GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GEtRightSubTree(cNode);
	}

	nNode = MakeBTreeNode();
	SetData(nNode, data);

	if (pNode != NULL)
	{
		if (data < GetData(pNode))
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	}
	else
	{
		*pRoot = nNode;
	}
}

// ���� Ž�� Ʈ���� ������� ������ Ž��
BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
	BTreeNode * cNode = bst;
	BSTData cd;

	while (cNode != NULL)
	{
		cd = GetData(cNode);

		if (target == cd)
			return cNode;
		else if (target < cd)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GEtRightSubTree(cNode);
	}
	return NULL;
}

// Ʈ������ ��带 �����ϰ� ���ŵ� ����� �ּ� ���� ��ȯ
BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target)
{
	BTreeNode * pVRoot = MakeBTreeNode();
	BTreeNode * pNode = pVRoot;
	BTreeNode * cNode = *pRoot;
	BTreeNode * dNode;

	ChangeRightSubTree(pVRoot, *pRoot);

	while (cNode != NULL && GetData(cNode) != target)
	{
		pNode = cNode;

		if (target < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GEtRightSubTree(cNode);
	}

	if (cNode == NULL)
		return NULL;
	dNode = cNode;

	if (GetLeftSubTree(dNode) == NULL && GEtRightSubTree(dNode) == NULL)
	{
		if (GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}
	else if (GetLeftSubTree(dNode) == NULL || GEtRightSubTree(dNode) == NULL)
	{
		BTreeNode * dcNode;

		if (GetLeftSubTree(dNode) != NULL)
			dcNode = GetLeftSubTree(dNode);
		else
			dcNode = GEtRightSubTree(dNode);

		if (GetLeftSubTree(pNode) == dNode)
			ChangeLeftSubTree(pNode, dcNode);
		else
			ChangeRightSubTree(pNode, dcNode);
	}
	else
	{
		BTreeNode * mNode = GEtRightSubTree(dNode);
		BTreeNode * mpNode = dNode;
		int delData;

		while (GetLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		delData = GetData(dNode);
		SetData(dNode, GetData(mNode));

		if (GetLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, GEtRightSubTree(mNode));
		else
			ChangeRightSubTree(mpNode, GEtRightSubTree(mNode));

		dNode = mNode;
		SetData(dNode, delData);
	}

	if (GEtRightSubTree(pVRoot) != *pRoot)
		*pRoot = GEtRightSubTree(pVRoot);

	free(pVRoot);
	return dNode;
}

void ShowIntData(int data)
{
	printf("%d ", data);
}

// ���� Ž�� Ʈ���� ����� ��� ����� ������ ���
void BSTShowAll(BTreeNode* bst)
{
	InorderTraverse(bst, ShowIntData);
}