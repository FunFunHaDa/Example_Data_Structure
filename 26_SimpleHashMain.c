#include<stdio.h>
#include<stdlib.h>
#include"26_Person.h"
#include"26_Table.h"

int MyHashFunc(int k)
{
	return k % 100;
}

int main(void)
{
	Table mytbl;
	Person * np;
	Person * rp;
	Person * sp;
	TBLInit(&mytbl, MyHashFunc);

	np = MakePersonData(20120003, "Lee", "Seoul");
	TBLInsert(&mytbl, GetSSN(np), np);

	np = MakePersonData(20130012, "KIM", "Jeju");
	TBLInsert(&mytbl, GetSSN(np), np);

	np = MakePersonData(20170049, "HAN", "Kangwon");
	TBLInsert(&mytbl, GetSSN(np), np);

	sp = TBLSearch(&mytbl, 20120003);
	if (sp != NULL)
		ShowPerInfo(sp);

	sp = TBLSearch(&mytbl, 20130012);
	if (sp != NULL)
		ShowPerInfo(sp);

	sp = TBLSearch(&mytbl, 20170049);
	if (sp != NULL)
		ShowPerInfo(sp);

	rp = TBLDelete(&mytbl, 20120003);
	if (rp != NULL)
		free(rp);
	rp = TBLDelete(&mytbl, 20130012);
	if (rp != NULL)
		free(rp);
	rp = TBLDelete(&mytbl, 20170049);
	if (rp != NULL)
		free(rp);
	return 0;
}