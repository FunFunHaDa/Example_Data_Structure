#include<stdio.h>
#include<stdlib.h>
#include"14_ArrayBaseStack.h"

void StackInit(Stack * pstack)
{
	pstack->topIndex = -1;
}
int SIsEmpty(Stack * pstack)
{
	if (pstack->topIndex == -1)
		return TRUE;
	else
		return FALSE;
}
void SPush(Stack * pstack, Data data)
{
	pstack->topIndex += 1;
	pstack->stackArr[pstack->topIndex] = data;
}
Data SPop(Stack * pstack)
{
	int rIdx;

	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!(SPop)");
		exit(-1);
	}
	rIdx = pstack->topIndex;
	pstack->topIndex -= 1;
	return pstack->stackArr[rIdx];
}
Data SPeek(Stack * pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!(SPeek)");
		exit(-1);
	}
	return pstack->stackArr[pstack->topIndex];
}