#include<stdio.h>
#include<stdlib.h>
#include "30_ListBaseStack.h"

void StackInit(Stack * pstack)
{
	pstack->head = NULL;
}
int SIsEmpty(Stack * pstack)
{
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = pstack->head;
	pstack->head = newNode;
}
Data SPop(Stack * psatck)
{
	Data rdata;
	Node * rnode;

	if (SIsEmpty(psatck))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}
	rdata = psatck->head->data;
	rnode = psatck->head;

	psatck->head = psatck->head->next;
	free(rnode);
	return rdata;
}
Data SPeek(Stack * pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}
	return pstack->head->data;
}