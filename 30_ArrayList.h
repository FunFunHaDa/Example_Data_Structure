#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__
#include "30_Point.h"
#define TRUE 1
#define FALSE 0

#define LIST_LEN 100
//typedef int LData;
typedef Point * LData;


typedef struct __ArrayList
{
	LData arr[LIST_LEN];
	int numOfData;
	int curPosition;
}ArrayList;

typedef ArrayList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plsit, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

#endif // !__ARRAY_LIST_H__
