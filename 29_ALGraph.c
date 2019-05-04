#include<stdio.h>
#include<stdlib.h>
#include "29_ALGraph.h"
#include "29_DLinkedList.h"

int WhoIsPrecede(int data1, int data2);

void GraphInit(ALGraph * pg, int nv)
{
	int i;

	pg->ajdList = (List*)malloc(sizeof(List)*nv);
	pg->numV = nv;
	pg->numE = 0;

	for (i = 0; i < nv; i++)
	{
		ListInit(&(pg->ajdList[i]));
		SetSortRule(&(pg->ajdList[i]), WhoIsPrecede);
	}
}
void GraphDestroy(ALGraph * pg)
{
	if (pg->ajdList != NULL)
		free(pg->ajdList);
}
void AddEdge(ALGraph * pg, int fromV, int toV)
{
	LInsert(&(pg->ajdList[fromV]), toV);
	LInsert(&(pg->ajdList[toV]), fromV);
	pg->numE += 1;
}
void ShowGraphEdgeInfo(ALGraph * pg)
{
	int i;
	int vx;

	for (i = 0; i < pg->numV; i++)
	{
		printf("%c�� ����� ����: ", i + 65);

		if (LFirst(&(pg->ajdList[i]), &vx))
		{
			printf("%c ", vx + 65);

			while (LNext(&(pg->ajdList[i]), &vx))
				printf("%c ", vx + 65);
		}
		printf("\n");
	}
}

int WhoIsPrecede(int data1, int data2)
{
	if (data1 < data2)
		return 0;
	else
		return 1;
}