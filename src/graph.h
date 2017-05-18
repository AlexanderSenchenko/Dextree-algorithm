#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>

struct graph {
	int nvertices;
	int *m;
	int *visited;
};

struct graph *graph_create(int vertices);
void graph_clear(struct graph *g);
void graph_free(struct graph *g);
void graph_set_edge(struct graph *g, int i, int j, int w);
int graph_get_edge(struct graph *g, int i, int j);

#endif
