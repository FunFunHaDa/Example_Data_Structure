#include<stdio.h>
#include<stdlib.h>
#include "3_Person.h"
#include "3_Table2.h"

int MyHashFunc(int k)
{
	return k % 100;
}

int main(void)
{
	Table myTBl;
	Person * np;
	Person * sp;
	Person * rp;

	TBLInit(&myTBl, MyHashFunc);

	np = MakePersonData(900254, "Lee", "Seoul");
	TBLInsert(&myTBl, GetSSN(np), np);

	np = MakePersonData(900139, "KIM", "Jeju");
	TBLInsert(&myTBl, GetSSN(np), np);

	np = MakePersonData(900827, "HAN", "Kangwon");
	TBLInsert(&myTBl, GetSSN(np), np);

	sp = TBLSearch(&myTBl, 900254);
	if (sp != NULL)
		ShowPerInfo(sp);


	sp = TBLSearch(&myTBl, 900139);
	if (sp != NULL)
		ShowPerInfo(sp);


	sp = TBLSearch(&myTBl, 900827);
	if (sp != NULL)
		ShowPerInfo(sp);

	rp = TBLDelete(&myTBl, 900254);
	if (rp != NULL)
		free(rp);

	rp = TBLDelete(&myTBl, 900139);
	if (rp != NULL)
		free(rp);

	rp = TBLDelete(&myTBl, 900827);
	if (rp != NULL)
		free(rp);

	return 0;
}