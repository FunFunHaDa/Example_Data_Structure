#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__
#include"5_Point.h" // p95

#define TRUE 1
#define FALSE 0

#define LIST_LEN 100
// typedef int LData;
typedef Point * LData; // p95

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
int LNext(List * plist, LData *  pdata);

LData LRemove(List * plist);
int LCount(List * plist);

#endif // !__ARRAY_LIST_H__