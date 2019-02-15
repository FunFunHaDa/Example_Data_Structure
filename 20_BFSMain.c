#include<stdio.h>
#include"20_ALGraphBFS.h"

int main(void)
{
	ALGraph graph;
	GraphInit(&graph, 7);

	AddEdge(&graph, A, B);
	AddEdge(&graph, A, D);
	AddEdge(&graph, B, C);
	AddEdge(&graph, D, C);
	AddEdge(&graph, D, E);
	AddEdge(&graph, E, F);
	AddEdge(&graph, E, G);

	ShowGraphEdgeInfo(&graph);
	BFShowGraphVerex(&graph, A); printf("\n");
	BFShowGraphVerex(&graph, C); printf("\n");
	BFShowGraphVerex(&graph, E); printf("\n");
	BFShowGraphVerex(&graph, G); printf("\n");
	GraphDestroy(&graph);
	return 0;
}