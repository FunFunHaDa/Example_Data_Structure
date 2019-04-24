#include<stdio.h>
#include "28_ArrayList.h"

void ListInit(List * plist)
{
	(plist->numOfData) = 0;
	(plist->curPostion) = -1;
}
void LInsert(List * plist, LData data)
{
	if (plist->numOfData >= LIST_LEN)
	{
		puts("������ �Ұ����մϴ�.");
		return;
	}
	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

int LFirst(List * plist, LData * pdata)
{
	if (plist->numOfData == 0)
		return FALSE;

	(plist->curPostion) = 0;
	*pdata = plist->arr[0];
	return TRUE;
}
int LNext(List * plist, LData * pdata)
{
	if (plist->curPostion >= (plist->numOfData) - 1)
		return FALSE;
	(plist->curPostion)++;
	*pdata = plist->arr[plist->curPostion];
	return TRUE;
}

LData LRemove(List * plist)
{
	int rpos = plist->curPostion;
	int num = plist->numOfData;
	int i;
	LData rdata = plist->arr[rpos];

	for (i = rpos; i < num - 1; i++)
		plist->arr[i] = plist->arr[i + 1];

	(plist->numOfData)--;
	(plist->curPostion)--;
	return rdata;
}
int LCount(List * plist)
{
	return plist->numOfData;
}