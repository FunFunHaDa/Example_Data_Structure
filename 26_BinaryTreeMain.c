#include<stdio.h>
#include "26_BinaryTree.h"

int main(void)
{
	BTreeNode * bt1 = MakeBtreeNode(); // ��� 1 ����
	BTreeNode * bt2 = MakeBtreeNode(); // ��� 2 ����
	BTreeNode * bt3 = MakeBtreeNode(); // ��� 3 ����
	BTreeNode * bt4 = MakeBtreeNode(); // ��� 4 ����

	SetData(bt1, 1);	// bt1�� ����
	SetData(bt2, 2);	// bt2�� ����
	SetData(bt3, 3);	// bt3�� ����
	SetData(bt4, 4);	// bt4�� ����

	MakeLeftSubTree(bt1, bt2);	// bt2�� bt1�� ���� �ڽ� ����
	MakeRightSubTree(bt1, bt3);	// bt3�� bt1�� ������ �ڽ� ����
	MakeLeftSubTree(bt2, bt4);	// bt4�� bt2�� ���� �ڽ� ����

	// bt1�� ���� �ڽ� ����� ������ ���
	printf("%d \n", GetData(GetLeftSubTree(bt1)));

	// bt1�� ���� �ڽ��� ���� �ڽ� ��� ������ ���
	printf("%d \n", GetData(GetLeftSubTree(GetLeftSubTree(bt1))));
	return 0;
}