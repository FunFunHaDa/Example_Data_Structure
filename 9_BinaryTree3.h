#ifndef __BINARY_TREE3_H__
#define __BINARY_TREE3_H__

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode * left;
	struct _bTreeNode * right;
}BTreeNode;

BTreeNode * MakeBTreeNode(void);
BTData GetData(BTreeNode * bt);
void SetData(BTreeNode * bt, BTData data);

BTreeNode * GetLeftSubTree(BTreeNode * bt);
BTreeNode * GetRightSubTree(BTreeNode * bt);

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub);
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub);

typedef void VisitFuncPtr(BTData data);

void PreorederTraverse(BTreeNode * bt, VisitFuncPtr action);
void InorederTraverse(BTreeNode * bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action);

BTreeNode * RemoveLeftSubTree(BTreeNode * bt);
BTreeNode * RemoveRightSubTree(BTreeNode * bt);
void ChangeLeftSubTree(BTreeNode * main, BTreeNode * sub);
void ChagneRightSubTree(BTreeNode * main, BTreeNode * sub);

#endif // !__BINARY_TREE3_H__
