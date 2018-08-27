#include <stdio.h>
#include <stdlib.h>
#include "45_Person.h"
#include "45_Table.h"

int MyHashFunc(int k)
{
	return k % 100;
}

int main(void)
{
	Table myTbl;
	Person * np;
	Person * sp;
	Person * rp;
	TBLInit(&myTbl, MyHashFunc);

	// 데이터 입력
	np = MakePersonData(20120003, "Lee", "Seout");
	TBLInsert(&myTbl, GetSSN(np), np);

	np = MakePersonData(20130012, "KIM", "Jeju");
	TBLInsert(&myTbl, GetSSN(np), np);

	np = MakePersonData(20170049, "HAN", "Kangwon");
	TBLInsert(&myTbl, GetSSN(np), np);

	// 데이터 탐색
	sp = TBLSerch(&myTbl, 20120003);
	if (sp != NULL)
		ShowPerInfo(sp);

	sp = TBLSerch(&myTbl, 20130012);
	if (sp != NULL)
		ShowPerInfo(sp);

	sp = TBLSerch(&myTbl, 20170049);
	if (sp != NULL)
		ShowPerInfo(sp);

	// 데이터 삭제
	rp = TBLDelete(&myTbl, 20120003);
	if (rp != NULL)
		free(rp);

	rp = TBLDelete(&myTbl, 20120012);
	if (rp != NULL)
		free(rp);

	rp = TBLDelete(&myTbl, 20170049);
	if (rp != NULL)
		free(rp);

	return 0;
}