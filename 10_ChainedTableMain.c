#include<stdio.h>
#include<stdlib.h>
#include "10_Person.h"
#include "10_Table2.h"

int MyHashFunc(int k)
{
	return k % 100;
}

int main(void)
{
	Table myTbl;
	Person* np;
	Person* sp;
	Person* rp;

	TBLInit(&myTbl, MyHashFunc);

	np = MakePersonData(900254, "Lee", "Seoul");
	TBLInsert(&myTbl, GetSSN(np), np);

	np = MakePersonData(900139, "KIM", "Jeju");
	TBLInsert(&myTbl, GetSSN(np), np);

	np = MakePersonData(900123, "Han", "Suwon");
	TBLInsert(&myTbl, GetSSN(np), np);

	sp = TBLSearch(&myTbl, 900254);
	if (sp != NULL)
		ShwoPerInfo(sp);

	sp = TBLSearch(&myTbl, 900139);
	if (sp != NULL)
		ShwoPerInfo(sp);

	sp = TBLSearch(&myTbl, 900123);
	if (sp != NULL)
		ShwoPerInfo(sp);

	rp = TBLDelete(&myTbl, 900254);
	if (rp != NULL)
		free(rp);

	rp = TBLDelete(&myTbl, 900139);
	if (rp != NULL)
		free(rp);

	rp = TBLDelete(&myTbl, 900123);
	if (rp != NULL)
		free(rp);

	return 0;
}