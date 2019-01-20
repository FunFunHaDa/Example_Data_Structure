#include<stdio.h>
#include<stdlib.h>
#include"17_Person.h"
#include "17_Table.h"

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

	np = MakePersonData(20120003, "Lee", "Seoul");
	TBLInsert(&myTbl, GETSSN(np), np);

	np = MakePersonData(20130012, "KIM", "Jeju");
	TBLInsert(&myTbl, GETSSN(np), np);

	np = MakePersonData(20170049, "HAN", "KangWon");
	TBLInsert(&myTbl, GETSSN(np), np);

	sp = TBLSerach(&myTbl, 20120003);
	if (sp != NULL)
		ShowPerInfo(sp);
	sp = TBLSerach(&myTbl, 20130012);
	if (sp != NULL)
		ShowPerInfo(sp);
	sp = TBLSerach(&myTbl, 20170049);
	if (sp != NULL)
		ShowPerInfo(sp);

	rp = TBLDelete(&myTbl, 20120003);
	if (rp != NULL)
		free(rp);
	rp = TBLDelete(&myTbl, 20130012);
	if (rp != NULL)
		free(rp);
	rp = TBLDelete(&myTbl, 20170049);
	if (rp != NULL)
		free(rp);
	return 0;
}