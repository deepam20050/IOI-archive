// https://dmoj.ca/problem/ccc98s5

#include "bits/stdc++.h"

using namespace std;
using pi = pair <int, pair <int, int>>;

const int N = 630, oo = 2e9;

int g[N][N], d[N][N];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int abso (int x) {
	return x < 0 ? -x: x;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				scanf("%d", &g[i][j]);
				d[i][j] = oo;
			}
		}
		priority_queue <pi, vector <pi>, greater <pi>> pq;
		pq.push({0,{1, 1}});
		d[1][1] = 0;
		while (!pq.empty()) {
			auto top = pq.top();
			pq.pop();
			int oxo = top.first, x = top.second.first, y = top.second.second;
			for (int i = 0; i < 4; ++i) {
				int x0 = x + dx[i], y0 = y + dy[i];
				if (1 <= x0 && x0 <= n && 1 <= y0 && y0 <= n && abso(g[x0][y0] - g[x][y]) <= 2){
					int add = 0;
					if (g[x0][y0] > g[1][1] || g[x][y] > g[1][1]) {
						add = 1;
					}
					if (d[x0][y0] > add + oxo) {
						d[x0][y0] = add + oxo;
						pq.push({d[x0][y0], {x0, y0}});
					}
				}
			}
		}
		// for (int i = 1; i <= n; ++i) {
		// 	for (int j = 1; j <= n; ++j) {
		// 		printf("%d ", d[i][j]);
		// 	}
		// 	puts("");
		// }
		if (d[n][n] == oo) {
			puts("CANNOT MAKE THE TRIP");
		} else {
			printf("%d\n", d[n][n]);
		}
	}
	return 0;
}