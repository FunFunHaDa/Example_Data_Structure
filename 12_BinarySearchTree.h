#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include "12_BinaryTree.h"
typedef BTData BSTData;

void BSTMakeAntInit(BTreeNode ** pRoot);
BSTData BSTGetNodeData(BTreeNode * bst);
void BSTInsert(BTreeNode ** pRoot, BSTData data);
BTreeNode * BSTSearch(BTreeNode * bst, BSTData target);
// 2
BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target);
void BSTShowAll(BTreeNode * bst);

#endif // !__BINARY_SEARCH_TREE_H__
