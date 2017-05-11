#include <stdio.h>

int g_i(int i, int j)
{
	return i * 5 + j;
}

void all(int g[], int len[], int vis[]) {
	for (int i = 0; i < 6; i++) {
		if (g[g_i(0, i)] > 0 && g[g_i(0, i)] < len[i]) {
				len[i] = g[g_i(0, i)];
				vis[i] = 0;
			}
	}
	
	for (int i = 0; i < 6; i++) {
		printf("%d)%d\t", i, len[i]);
	}
	printf("\n");

	for (int i = 0; i < 6; i++) {
		printf("%d)%d\t", i, vis[i]);
	}
	printf("\n\n");

	for (int z = 0; z < 6; z++) {
		for (int i = 0; i < 6; i++) {
			if (vis[i] == z) {
				for (int j = 0; j < 6; j++) {
					if (g[g_i(i, j)] > 0) {
						if (g[g_i(i, j)] + len[i] < len[j]) {
							len[j] = g[g_i(i, j)] + len[i];
							vis[j] = i;
						}
					}
				}
				
			}
		}
	}

	for (int i = 0; i < 6; i++) {
		printf("%d)%d\t", i, len[i]);
	}
	printf("\n");

	for (int i = 0; i < 6; i++) {
		printf("%d)%d\t", i, vis[i]);
	}
	printf("\n");
}
