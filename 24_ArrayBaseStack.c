#include<stdio.h>
#include<stdlib.h>
#include"24_ArrayBaseStack.h"

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
Data SPop(Stack * psatck)
{
	int rIdx;
	if (SIsEmpty(psatck))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}
	rIdx = psatck->topIndex;
	psatck->topIndex -= 1;

	return psatck->stackArr[rIdx];
}
Data SPeek(Stack * pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}
	return pstack->stackArr[pstack->topIndex];
}