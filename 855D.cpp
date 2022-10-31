#include <bits/stdc++.h>

using namespace std;

inline void dfs1 (int x, int p = 0, int depth = 0, int w_0 = 0) {
	tin[x] = ++timer;
	height[x] = depth;
	up[x][0] = p;
	to_1[x][0] = w_0;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int p, x;
		scanf("%d %d", &p, &x);
		if (p == -1 && x == -1) {
			start = i;
		} else {
			g[p].push_back({i, x});
		}
	}
	return 0;
}