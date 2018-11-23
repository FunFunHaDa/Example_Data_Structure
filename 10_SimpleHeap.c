#include "10_SimpleHeap.h"

void HeapInit(Heap * ph)
{
	ph->numOfData = 0;
}

int HIsEmpty(Heap * ph)
{
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx)
{
	return idx / 2;
}

int GetLChildIDX(int idx)
{
	return idx * 2;
}

int GetRChildIDX(int idx)
{
	return GetLChildIDX(idx) + 1;
}

int GetHiPriChildIDX(Heap * ph, int idx)
{
	if (GetLChildIDX(idx) > ph->numOfData)
		return 0;
	else if (GetLChildIDX(idx) == ph->numOfData)
		return GetLChildIDX(idx);
	else
	{
		if (ph->heapAr[GetLChildIDX(idx)].pr > ph->heapAr[GetRChildIDX(idx)].pr)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

void HInsert(Heap * ph, HData data, Priority pr)
{
	int idx = ph->numOfData + 1;
	HeapElem nelem = { pr, data };

	while (idx != 1)
	{
		if (pr < (ph->heapAr[GetParentIDX(idx)].pr))
		{
			ph->heapAr[idx] = ph->heapAr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
			break;
	}
	ph->heapAr[idx] = nelem;
	ph->numOfData += 1;
}

HData HDelete(Heap * ph)
{
	HData retData = (ph->heapAr[1]).data;
	HeapElem lastElem = ph->heapAr[ph->numOfData];

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHiPriChildIDX(ph, parentIdx))
	{
		if (lastElem.pr <= ph->heapAr[childIdx].pr)
			break;
		ph->heapAr[parentIdx] = ph->heapAr[childIdx];
		parentIdx = childIdx;
	}
	ph->heapAr[parentIdx] = lastElem;
	ph->numOfData -= 1;;
	return retData;
}