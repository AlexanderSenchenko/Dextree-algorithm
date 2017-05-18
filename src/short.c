#include "graph.h"
#include "short.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binaryheap.h"
#include <limits.h>

void ShortestPath_Dijkstra(struct graph *g, int src, int *d, int *prev)
{	
	struct heap *h;
	struct heapnode v;

	// Создаем пустую кучу
	h = heap_create(g->nvertices);
	//Добавляем в кучу вершины с приоритетом
	for (int i = 1; i <= g->nvertices; i++) {
		d[i] = (i != src) ? INT_MAX : 0;
		prev[i] = -1;
		heap_insert(h, d[i], i);
	}
	
	for (int i = 1; i <= g->nvertices; i++) {
		// Извлекаем узел ближайший к начальному
		v = heap_extract_min(h);

		// Отмечаем v как посещенный
		g->visited[v.value - 1] = 1;

			// Цикл по смежным вершинам узла v
			for (int j = 1; j <= g->nvertices; j++) {
				if (graph_get_edge(g, v.value, j) && !g->visited[j - 1]) {
					if (d[v.value] + graph_get_edge(g, v.value, j) < d[j]) {
						d[j] = d[v.value] + graph_get_edge(g, v.value, j);
						heap_decrease_key(h, j, d[j]);
						prev[j] = v.value;
					}
				}
			}
	}
	heap_free(h);
}

void SearchShortestPath(int *prev, int src, int dst, int *pathlen, int *path)
{
	int i;
	int j;

	*pathlen = 1;
	i = dst;

	
	while (i != src) {
		(*pathlen)++;
		i = prev[i];
	}

	j = 0;
	i = dst;

	while (i != src) {
		path[*pathlen - j] = i;
		i = prev[i];
		j++;
	}
	path[*pathlen - j] = i;

}
