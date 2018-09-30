#ifndef __TABLE2_H__
#define __TABLE2_H__

#include "Slot2.h"

typedef struct _table
{
	List tbl[MAX_TBL];
	HashFunc * hf;
}Table;

void TBLInit(Table *pt, HashFunc * f);
void TBLInsert(Table * pt, Key k, Value v);
Value TBLDelete(Table * pt, Key k);
Value TBLSearch(Table * pt, Key k);

#endif // !__TABLE2_H__
