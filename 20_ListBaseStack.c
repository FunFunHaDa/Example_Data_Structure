#include<stdio.h>
#include<stdlib.h>
#include "20_ListBaseStack.h"

void StackInit(Stack * pstack)
{
	pstack->head = NULL;
}
int SisEmpty(Stack * pstack)
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
Data SPop(Stack * pstack)
{
	Data rdata;
	Node * rnode;

	if (SisEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}
	rdata = pstack->head->data;
	rnode = pstack->head;
	pstack->head = pstack->head->next;
	free(rnode);
	return rdata;
}
Data SPeek(Stack * pstack)
{
	if (SisEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}
	return pstack->head->data;
}
