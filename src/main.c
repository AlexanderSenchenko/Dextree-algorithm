#include <stdio.h>
#include "graph.h"

int main()
{
	FILE *in = fopen("graph.txt", "r");
	int graph[25];
	int len[5];
	int vis[5];

	for (int i = 0; i < 25; i++) {
		fscanf(in, "%d", &graph[i]);
	}

	for (int i = 0; i < 5; i++) {
		len[i] = 100;
		vis[i] = -1;
	}
	len[0] = 0;
	
	all(graph, len, vis);
	
	fclose(in);
	return 0;
}
