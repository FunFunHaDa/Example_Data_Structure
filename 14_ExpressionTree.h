#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include "14_BinaryTree.h"

BTreeNode * MakeExpTree(char exp[]);
int EvalulateExpTree(BTreeNode * bt);

void ShowPrefixTypeExp(BTreeNode * bt);
void ShowInfixTypeExp(BTreeNode * bt);
void ShowPostfixTypeExp(BTreeNode * bt);
#endif // !__EXPRESSION_TREE_H__
