#ifndef __TABLE2_H__
#define __TABLE2_H__

#include "29_Slot2.h"
#include "29_DLinkedList.h"

#define MAX_TBL 100

typedef int HashFunc(Key k);

typedef struct _table
{
	List tbl[MAX_TBL];
	HashFunc * hf;
}Table;

void TBLInit(Table * pt, HashFunc * f);
void TBLInsert(Table * pt, Key k, Value v);
Value TBLDelete(Table * pt, Key k);
Value TBLSearch(Table * pt, Key k);

#endif // !__TABLE2_H__
