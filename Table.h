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

// 초기화
void TBLInit(Table * pt, HashFunc * f);
// 키와 캆을 테이블에 저장
void TBLInsert(Table * pt, Key k, Value v);
// 키를 근거로 데이터 삭제
Value TBLDelete(Table * pt, Key k);
// 키를 근거로 데이터 탐색
Value TBLSearch(Table * pt, Key k);

#endif // !__TABLE_H__
