#include<stdio.h>
#include "BinaryTree2.h"
#include "BinarySearchTree.h"

// 초기화
void BSTMakeAndInit(BTreeNode ** pRoot)
{
	*pRoot = NULL;
}

// 노드의 데이터 반환
BSTData BSTGetNodeData(BTreeNode * bst)
{
	return GetData(bst);
}

// BST를 대상으로 데이터 저장
void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
	BTreeNode * pNode = NULL; // parent Node
	BTreeNode * cNode = *pRoot; // current Node
	BTreeNode * nNode = NULL;	// new node

	while (cNode != NULL)
	{
		if (data == GetData(cNode))
			return;

		pNode = cNode;

		if (GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}
	
	nNode = MakeBTreeNode(); // 새 노드의 생성
	SetData(nNode, data);	// 새 노드에 데이터 저장

	// pNode의 자식 노드로 새 노드를 추가
	if (pNode != NULL)
	{
		if (data < GetData(pNode))
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	}
	else // 새 노드가 루트 노드라면
	{
		*pRoot = nNode;
	}
}

// BST를 대상으로 데이터 탐색
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
			cNode = GetRightSubTree(cNode);
	}
	return NULL; // 탐색대상이 저장되어 있지 않음
}