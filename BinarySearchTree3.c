#include<stdio.h>
#include<stdlib.h>
#include"BinaryTree3.h"
#include "BinarySearchTree2.h"
#include "AVLRebalance.h"

// 이진 탐색 트리의 생성 및 초기화
void BSTMakeAndInit(BTreeNode ** pRoot)
{
	*pRoot = NULL;
}

// 노드에 저장된 데이터 반환
BSTData BSTGetNodeData(BTreeNode * bst)
{
	return GetData(bst);
}

// 이진 탐색 트리를 대상으로 데이터 저장
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

	*pRoot = Rebalance(pRoot); //
}

// 이진 탐색 트리를 대상으로 데이터 탐색
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

// 트리에서 노드를 제거하고 제거된 노드의 주소 값을 반환
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

	*pRoot = Rebalance(pRoot); //
	return dNode;
}

void ShowIntData(int data)
{
	printf("%d ", data);
}

// 이진 탐색 트리에 저장된 모든 노드의 데이터 출력
void BSTShowAll(BTreeNode* bst)
{
	InorderTraverse(bst, ShowIntData);
}