#ifndef __AL_GRAPH_KRUSKAL__
#define __AL_GRPAH_KRUSKAL__

#include "7_DLinkedList.h"
#include "7_PriorityQueue.h"
#include "7_ALEdge.h"

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
void DFShowGraphVertex(ALGraph * pg, int startV);
void ConKruskalMST(ALGraph *  pg);
void ShowGraphEdgeWeightInfo(ALGraph * pg);

#endif // !__AL_GRAPH_KRUSKAL__
