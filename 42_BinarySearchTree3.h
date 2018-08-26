#ifndef __BINARY_SEARCH_TREE2_H__
#define __BINARY_SEARCH_TREE2_H__

#include "41_BinaryTree3.h"

typedef BTData BSTData;

// ���� Ž�� Ʈ���� ���� �� �ʱ�ȭ
void BSTMakeAndInit(BTreeNode ** pRoot);

// ��忡 ����� ������ ��ȯ
BSTData BSTGetNodeData(BTreeNode * bst);

// ���� Ž�� Ʈ���� ������� ������ ����(����� �������� ����)
void BSTInsert(BTreeNode ** pRoot, BSTData data);

// ���� Ž�� Ʈ���� ������� ������ Ž��
BTreeNode * BSTSearch(BTreeNode * bst, BSTData target);

// Ʈ������ ��带 �����ϰ� ���ŵ� ����� �ּ� ���� ��ȯ
BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target);

// Ʈ������ ��带 �����ϰ� ���ŵ� ����� �ּ� ���� ��ȯ
void BSTShowAll(BTreeNode * bst);

#endif // !__BINARY_SEARCH_TREE2_H__
