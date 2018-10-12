#include<stdio.h>
#include "5_ALGraphDFS.h"

int main(void)
{
	ALGraph graph;
	GraphInit(&graph);

	AddEdge(&graph, A, B);
	AddEdge(&graph, A, B);
	AddEdge(&graph, B, B);
	AddEdge(&graph, D, B);
	AddEdge(&graph, D, B);

}