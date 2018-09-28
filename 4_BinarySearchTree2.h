#ifndef __BINARY_SEARCH_TREE_H__
#define __BIANRY_SEARCH_TREE_H__

#include "4_BinaryTree3.h"

typedef BTData BSTData;

void BSTMakeAndInit(BTreeNode ** pRoot);
BSTData BSTGetNodeDdata(BTreeNode * bst);
void BSTInsert(BTreeNode ** pRoot, BSTData data);
BTreeNode * BSTSearch(BTreeNode * bst, BSTData target);
BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target);
void BSTShowAll(BTreeNode * bst);

#endif // !__BINARY_SEARCH_TREE_H__
