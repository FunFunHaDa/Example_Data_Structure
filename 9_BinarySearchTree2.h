#ifndef __BINARY_SEARCH_TREE2_H__
#define __BINARY_SEARCH_TREE2_H__

#include "9_BinaryTree3.h"

typedef BTData BSTData;

void BSTMakeAndInit(BTreeNode ** pRoot);
BSTData BSTGetNodeData(BTreeNode * bst);
void BSTInsert(BTreeNode ** pRoot, BSTData data);
BTreeNode * BSTSearch(BTreeNode * bst, BSTData data);
BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target);
void BSTShowAll(BTreeNode * bst);
#endif // !__BINARY_SEARCH_TREE2_H__
