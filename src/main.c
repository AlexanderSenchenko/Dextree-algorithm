#include <stdio.h>
#include "graph.h"

int main()
{
	FILE *in = fopen("graph.txt", "r");
	int graph[36];
	int len[6];
	int vis[6];

	for (int i = 0; i < 36; i++) {
		fscanf(in, "%d", &graph[i]);
	}

	for (int i = 0; i < 6; i++) {
		len[i] = 100;
		vis[i] = -1;
	}
	len[0] = 0;
	
	all(graph, len, vis);
	
	fclose(in);
	return 0;
}
