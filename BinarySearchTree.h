#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include "BinaryTree2.h"

typedef BTData BSTData;

// �ʱ�ȭ
void BSTMakeAndInit(BTreeNode ** pRoot);

// ����� ������ ��ȯ
BSTData BSTGetNodeData(BTreeNode * bst);

// BST�� ������� ������ ����
void BSTInsert(BTreeNode ** pRoot, BSTData data);

// BST�� ������� ������ Ž��
BTreeNode * BSTSearch(BTreeNode * bst, BSTData target);

#endif // !__BINARY_SEARCH_TREE_H__