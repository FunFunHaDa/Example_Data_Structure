#include<stdio.h>
#include"27_ALGraph.h"

int main(void)
{
	ALGraph graph;
	GraphInit(&graph, 5);

	AddEdge(&graph, A, B);
	AddEdge(&graph, A, D);
	AddEdge(&graph, B, C);
	AddEdge(&graph, C, D);
	AddEdge(&graph, D, E);
	AddEdge(&graph, E, A);
	ShowGraphEdgeInfo(&graph);
	GraphDestroy(&graph);
	return 0;
}