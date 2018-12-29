#ifndef __AL_GRAPH_KRUSKAL__
#define __AL_GRAPH_KRUSKAL__

#include "14_DLinkedListt.h"
#include "14_PriorityQueue.h"
#include "14_ALEdge.h"

enum { A, B, C, D, E, F, G, H, I, J };

typedef struct _ual
{
	int numV;
	int numE;
	List * adjList;
	int * visitInfo;
	PQueue pqueue;
}ALGraph;

void GraphInit(ALGraph * pg, int nv);
void GraphDestroy(ALGraph * pg);
void AddEdge(ALGraph * pg, int fromV, int toV, int weight);
void ShowGraphEdgeInfo(ALGraph * pg);
void ConKruskalMST(ALGraph * pg);
void ShowGraphEdgeWeightInfo(ALGraph * pg);

#endif // !__AL_GRAPH_KRUSKAL__
