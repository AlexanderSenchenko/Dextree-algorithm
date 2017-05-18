#include "graph.h"


struct graph *graph_create(int vertices)
{
	struct graph *g;

	g = malloc(sizeof(*g));
	g->nvertices = vertices;
	g->visited = malloc(sizeof(int) * vertices);
	g->m = malloc(sizeof(int) * vertices * vertices);
	graph_clear(g);
	return g;
}


void graph_clear(struct graph *g)
{
	int i;
	int j;

	for (i = 0; i < g->nvertices; i++) {
		g->visited[i] = 0;
		for (j = 0; j < g->nvertices; j++) {
			g->m[i * g->nvertices + j] = 0;
		}
	}
}


void graph_free(struct graph *g)
{
	free(g->m);
	free(g);
}


void graph_set_edge(struct graph *g, int i, int j, int w)
{
	g->m[(i - 1) * g->nvertices + j - 1] = w;
	g->m[(j - 1) * g->nvertices + i - 1] = w;
}


int graph_get_edge(struct graph *g, int i, int j)
{
	return g->m[(i - 1) * g->nvertices + j - 1];
}
