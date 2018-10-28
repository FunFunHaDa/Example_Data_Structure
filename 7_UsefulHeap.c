#include "7_UsefulHeap.h"


void HeapInit(Heap * ph, PriorityComp pc)
{
	ph->numOfData = 0;
	ph->comp = pc;
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
		if (ph->comp(ph->HeapArr[GetLChildIDX(idx)], ph->HeapArr[GetRChildIDX(idx)]) < 0)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}


void HInsert(Heap * ph, HData data)
{
	int idx = ph->numOfData + 1;

	while (idx != 1)
	{
		if (ph->comp(data, ph->HeapArr[GetParentIDX(idx)]) > 0)
		{
			ph->HeapArr[idx] = ph->HeapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
		{
			break;
		}
	}
	ph->HeapArr[idx] = data;
	ph->numOfData += 1;
}
HData HDelete(Heap * ph)
{
	HData retData = ph->HeapArr[1];
	HData lastElem = ph->HeapArr[ph->numOfData];

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHiPriChildIDX(ph, parentIdx))
	{
		if (ph->comp(lastElem, ph->HeapArr[childIdx]) >= 0)
			break;

		ph->HeapArr[parentIdx] = ph->HeapArr[childIdx];
		parentIdx = childIdx;
	}
	ph->HeapArr[parentIdx] = lastElem;
	ph->numOfData -= 1;
	return retData;
}
