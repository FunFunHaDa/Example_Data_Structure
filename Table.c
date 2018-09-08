#include<stdio.h>
#include<stdlib.h>
#include "Table.h"

// √ ±‚»≠
void TBLInit(Table * pt, HashFunc * f)
{
	int i;

	for (i = 0; i < MAX_TBL; i++)
		(pt->tbl[i]).status = EMPTY;

	pt->hf = f;
}

// ≈∞øÕ Øì¿ª ≈◊¿Ã∫Ìø° ¿˙¿Â
void TBLInsert(Table * pt, Key k, Value v)
{
	int hv = pt->hf(k);
	pt->tbl[hv].val = v;
	pt->tbl[hv].key = k;
	pt->tbl[hv].status = INUSE;
}

// ≈∞∏¶ ±Ÿ∞≈∑Œ µ•¿Ã≈Õ ªË¡¶
Value TBLDelete(Table * pt, Key k)
{
	int hv = pt->hf(k);

	if ((pt->tbl[hv]).status != INUSE)
	{
		return NULL;
	}
	else
	{
		(pt->tbl[hv]).status = DELETED;
		return (pt->tbl[hv]).val;
	}
}

// ≈∞∏¶ ±Ÿ∞≈∑Œ µ•¿Ã≈Õ ≈Ωªˆ
Value TBLSearch(Table * pt, Key k)
{
	int hv = pt->hf(k);

	if ((pt->tbl[hv]).status != INUSE)
		return NULL;
	else
		return (pt->tbl[hv]).val;
}