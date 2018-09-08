#ifndef __TABLE_H__
#define __TABLE_H__

#include "Slot.h"
#define MAX_TBL 100

typedef int HashFunc(Key k);

typedef struct _table
{
	Slot tbl[MAX_TBL];
	HashFunc * hf;
}Table;

// √ ±‚»≠
void TBLInit(Table * pt, HashFunc * f);
// ≈∞øÕ Øì¿ª ≈◊¿Ã∫Ìø° ¿˙¿Â
void TBLInsert(Table * pt, Key k, Value v);
// ≈∞∏¶ ±Ÿ∞≈∑Œ µ•¿Ã≈Õ ªË¡¶
Value TBLDelete(Table * pt, Key k);
// ≈∞∏¶ ±Ÿ∞≈∑Œ µ•¿Ã≈Õ ≈Ωªˆ
Value TBLSearch(Table * pt, Key k);

#endif // !__TABLE_H__
