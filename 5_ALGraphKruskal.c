#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "5_ALGraphKruskal.h"
#include "5_DLinkedList.h"
#include "5_ArrayBaseStack.h"


int PQweightComp(Edge d1, Edge d2);

int WhoIsPrecede(int data1, int data2)
{
	if (data1 < data2)
		return 0;
	else
		return 1;
}

int VisitVertex(ALGraph * pg, int visitV)
{
	if (pg->visitInfo[visitV] == 0)
	{
		pg->visitInfo[visitV] = 1;
		return TRUE;
	}
	return FALSE;
}

void GraphInit(ALGraph * pg, int nv)
{
	int i;
	pg->adjList = (List*)malloc(sizeof(List)*nv);
	pg->numV = nv;
	pg->numE = 0;

	for (i = 0; i < nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}
	pg->visitInfo = (int*)malloc(sizeof(int)*pg->numV);
	memset(pg->visitInfo, 0, sizeof(int)*pg->numV);

	PQueueInit(&(pg->pqueue
		), PQweightComp);
}
void GraphDestroy(ALGraph * pg)
{
	if (pg->adjList != NULL)
		free(pg->adjList);
	if (pg->visitInfo != NULL)
		free(pg->visitInfo);
}


void AddEdge(ALGraph * pg, int fromV, int toV, int weight)
{
	Edge edge = { fromV, toV, weight };
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;
	PEnqueue(&(pg->pqueue), edge);
}

void RecoverEdge(ALGraph * pg, int fromV, int toV, int weight)
{
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	(pg->numE)++;
}

void RemoveWayEdge(ALGraph * pg, int fromV, int toV)
{
	int edge;
	if (LFirst(&(pg->adjList[fromV]), &edge))
	{
		if (edge == toV)
		{
			LRemove(&(pg->adjList[fromV]));
			return;
		}
		while (LNext(&(pg->adjList[fromV]), &edge))
		{
			if (edge == toV)
			{
				LRemove(&(pg->adjList[fromV]));
				return;
			}
		}
	}
}

void RemoveEdge(ALGraph *pg, int fromV, int toV)
{
	RemoveEdge(pg, fromV, toV);
	RemoveEdge(pg, toV, fromV);
	(pg->numE)--;
}

int PQweightComp(Edge d1, Edge d2)
{
	return d1.weight - d2.weight;
}

void DFShowGraphVertex(ALGraph *pg, int startV);
void ConKruskalMST(ALGraph * pg);
void showGraphEdgeWeightInfo(ALGraph * pg);