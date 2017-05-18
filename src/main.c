#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "binaryheap.h"
#include "graph.h"
#include "short.h"

int main(int argc, char **argv)
{
	int src;
	int pathlen;

	struct graph *g;
	
	FILE *A;
	A = fopen(argv[1], "r");
	if (A == NULL) {
		return 0;
	}
	src = atoi(argv[2]);
	int vertex;
	int edge;
	
	fscanf(A, "%d", &vertex); //number of vertex
	fscanf(A, "%d", &edge);	//number of edge

	g = graph_create(vertex);//create graph
	
	int weight_edge;
	int v1;//vertex #1
	int v2;//vertex #2

	for (int i = 0; i < edge; i++) {
		fscanf(A, "%d %d %d", &v1, &v2, &weight_edge);
		graph_set_edge(g, v1, v2, weight_edge);
	}

	// Выделяем место под массив минимальных весов
	int *d = (int*) malloc((g->nvertices + 1) * sizeof(int));

	// Выделяем место под массив кратчайших путей
	int *prev = (int*) malloc((g->nvertices + 1) * sizeof(int));
	
	ShortestPath_Dijkstra(g, src, d, prev);
	
	int path[g->nvertices];

	for (int j = 1; j <= g->nvertices; j++) {
		if (j != src) {
			SearchShortestPath(prev, src, j, &pathlen, path);

			printf("Min path %d -> %d: ", src, j);

			for (int i = 1; i <= pathlen; i++) {
				if (i == pathlen) {
					printf("%d\n", path[i]);
				}
				else printf("%d -> ", path[i]);
			}
			printf("Weight : %d\n", d[j]);
		}
	}

	graph_free(g);
	free(prev);
	free(d);

	return 0;
}
