#include<stdio.h>
#include<stdlib.h>
#include "30_ArrayBaseStack.h"

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
		printf("Stack Memory Error!");
		exit(-1);
	}
	rIdx = pstack->topIndex;
	pstack->topIndex -= 1;
	return pstack->stackArr[rIdx];
}
Data SPeek(Stack * psatck)
{
	if (SIsEmpty(psatck))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}
	return psatck->stackArr[psatck->topIndex];
}