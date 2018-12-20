#ifndef __TABLE_H__
#define __TABLE_H__

#include "13_Slot.h"
#include "13_DLinkedList.h" // Table2

#define MAX_TBL 100
typedef int HashFunc(Key k);
typedef struct _table
{
	// Slot tbl[MAX_TBL];
	List tbl[MAX_TBL]; // Table2
	HashFunc * hf;
}Table;

void TBLInit(Table * pt, HashFunc * f);
void TBLInsert(Table * pt, Key k, Value v);
Value TBLDelete(Table * pt, Key k);
Value TBLSearch(Table * pt, Key k);
#endif // !__TABLE_H__
