#include<stdio.h>
#include<stdlib.h>
#include "19_Person.h"
#include "19_Table2.h"

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

	np = MakePersonData(900254, "Lee", "Seoul");
	puts("asf");
	TBLInsert(&myTbl, GetSSN(np), np);
	puts("asf");
	np = MakePersonData(900139, "KIM", "Jeju");
	puts("asf");
	TBLInsert(&myTbl, GetSSN(np), np);
	np = MakePersonData(900827, "HAN", "Kangwon");
	TBLInsert(&myTbl, GetSSN(np), np);

	sp = TBLSearch(&myTbl, 900254);
	if (sp != NULL)
		ShowPerInfo(sp);
	sp = TBLSearch(&myTbl, 900139);
	if (sp != NULL)
		ShowPerInfo(sp);
	sp = TBLSearch(&myTbl, 900827);
	if (sp != NULL)
		ShowPerInfo(sp);
	
	rp = TBLDelete(&myTbl, 900254);
	if (rp != NULL)
		free(rp);
	rp = TBLDelete(&myTbl, 900139);
	if (rp != NULL)
		free(rp);
	rp = TBLDelete(&myTbl, 900827);
	if (rp != NULL)
		free(rp);
	return 0;
}