#include<stdio.h>
#include<stdlib.h>
#include "24_CLinkedList.h"

void ListInit(List * plist)
{
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}
void LInsertFront(List * plist, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
	}
	(plist->numOfData)++;
}

void LInsert(List * plist, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;
	}
	(plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
	if (plist->tail == NULL)
		return FALSE;

	plist->before = plist->tail;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}
int LNext(List * plist, Data * pdata);
Data LRemove(List * plist);
int LCount(List * plist);