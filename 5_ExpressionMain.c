#include<stdio.h>
#include "5_ExpressionTree.h"

int main(void)
{
	char exp[] = "12+7*";
	BTreeNode * eTree = MakeExpTree(exp);

	printf("���� ǥ����� ����: ");
	ShowPrefixTypeExp(eTree); printf("\n");

	printf("���� ǥ����� ����: ");
	ShowInifxTypeExp(eTree); printf("\n");

	printf("���� ǥ����� ����: ");
	ShowPostfixTypeExp(eTree); printf("\n");

	printf("������ ���: %d \n", EvaluateExpTree(eTree));

	return 0;
}