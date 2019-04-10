#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include "27_BinaryTree.h"
BTreeNode * MakeExpTree(char exp[]);
int EvaluateExpTree(BTreeNode * bt);

void ShowPrefixTypeExp(BTreeNode * bt);
void ShowInfixTypeExp(BTreeNode * bt);
void ShowPostfixTypeExp(BTreeNode * bt);

#endif // !__EXPRESSION_TREE_H__
