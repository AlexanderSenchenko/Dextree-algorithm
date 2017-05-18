#ifndef SHORT_H
#define SHORT_H

#include "graph.h"

void ShortestPath_Dijkstra(struct graph *g, int src, int *d, int *prev);
void SearchShortestPath(int *prev, int src, int dst, int *pathlen, int *path);

#endif
