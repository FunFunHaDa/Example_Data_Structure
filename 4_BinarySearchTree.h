#ifndef __BINARY_SEARCH_TREE_H__
#define __BIANRY_SEARCH_TREE_H__

#include "4_BinaryTree2.h"

typedef BTData BSTData;

void BSTMakeAndInit(BTreeNode ** pRoot);
BSTData BSTGetNodeDdata(BTreeNode * bst);
void BSTInsert(BTreeNode ** pRoot, BSTData data);
BTreeNode * BSTSearch(BTreeNode * bst, BSTData target);

#endif // !__BINARY_SEARCH_TREE_H__
