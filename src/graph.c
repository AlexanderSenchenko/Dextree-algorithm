#include <stdio.h>

int g_i(int i, int j)
{
	return i * 5 + j;
}

void all(int g[], int len[], int vis[]) {
	for (int i = 0; i < 5; i++) {
		if (g[g_i(0, i)] > 0 && g[g_i(0, i)] < len[i]) {
				len[i] = g[g_i(0, i)];
				vis[i] = 0;
			}
	}//len{0.40.0.0.18}//vis{0.1.0.0.1}
	/*for (int i = 0; i < 5; i++) {
		if (vis[i] == 0) {//vis[1]=0
			for (int j = 0; j < 5; j++) {
				if (g[g_i(i, j)] > 0) {//i = 1 j = 2
					if (g[g_i(i, j)] + len[i] < len[j]) {//22+(len[j] = 0) < 100 (+)
						len[j] = g[g_i(i, j)] + len[i];
						vis[j] = i;
					}
				}
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		if (vis[i] == 1) {
			for (int j = 0; j < 5; j++) {
				if (g[g_i(i, j)] > 0) {
					if (g[g_i(i, j)] + len[i] < len[j]) {
						len[j] = g[g_i(i, j)] + len[i];
						vis[j] = i;
					}
				}
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		if (vis[i] == 2) {
			for (int j = 0; j < 5; j++) {
				if (g[g_i(i, j)] > 0) {
					if (g[g_i(i, j)] + len[i] < len[j]) {
						len[j] = g[g_i(i, j)] + len[i];
						vis[j] = i;
					}
				}
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		if (vis[i] == 3) {
			for (int j = 0; j < 5; j++) {
				if (g[g_i(i, j)] > 0) {
					if (g[g_i(i, j)] + len[i] < len[j]) {
						len[j] = g[g_i(i, j)] + len[i];
						vis[j] = i;
					}
				}
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		if (vis[i] == 4) {
			for (int j = 0; j < 5; j++) {
				if (g[g_i(i, j)] > 0) {
					if (g[g_i(i, j)] + len[i] < len[j]) {
						len[j] = g[g_i(i, j)] + len[i];
						vis[j] = i;
					}
				}
			}
		}
	}*/

	for (int z = 0; z < 5; z++) {
		for (int i = 0; i < 5; i++) {
			if (vis[i] == z) {
				for (int j = 0; j < 5; j++) {
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

	for (int i = 0; i < 5; i++) {
		printf("%d)%d\t", i + 1, len[i]);
	}
	printf("\n");

	for (int i = 0; i < 5; i++) {
		printf("%d)%d\t", i + 1, vis[i] + 1);
	}
	printf("\n");
}
