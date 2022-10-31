// http://www.spoj.com/problems/QTREE2/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
const int LN = 17;

vector < pair < int, int > > g[N];
int tin[N];
int tout[N];
long long dist[N][LN];
int up[N][LN];
int height[N];
char s[10];
int tc;
int n;
int timer;

inline void dfs1 (int x, int p, int dist_p = 0, int depth = 0) {
	tin[x] = ++timer;
	height[x] = depth;
	up[x][0] = p;
	dist[x][0] = dist_p;
	for (int i = 1; i < LN; ++i) {
		up[x][i] = up[up[x][i - 1]][i - 1];
		dist[x][i] = dist[x][i - 1] + dist[up[x][i - 1]][i - 1];
	}
	for (auto &e: g[x]) {
		int to = e.first;
		int weight = e.second;
		if (to != p) {
			dfs1(to, x, weight, depth + 1);
		}
	}
	tout[x] = ++timer;
}

bool is_ancestor (int x, int y) {
	return tin[x] <= tin[y] && tout[x] >= tout[y];
}

int lca (int x, int y) {
	if (is_ancestor(x, y)) {
		return x;
	}
	if (is_ancestor(y, x)) {
		return y;
	}
	for (int i = LN - 1; i >= 0; --i) {
		if (!is_ancestor(up[x][i], y)) {
			x = up[x][i];
		}
	}
	return up[x][0];
}

int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		timer = 0;
		tin[0] = -1;
		tout[0] = 2e9;
		for (int i = 1; i <= n; ++i) {
			g[i].clear();
			memset(dist[i], 0LL, sizeof dist[i]);
		}
		for (int i = 1; i < n; ++i) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			g[x].push_back({y, z});
			g[y].push_back({x, z});
		}
		dfs1(1, 0);
		while (scanf("%s", s)) {
			if (s[0] == 'D' && s[1] == 'O') {
				break;
			}
			if (s[0] == 'D') {
				int a, b;
				scanf("%d %d", &a, &b);
				int dad = lca(a, b);
				int edges = height[a] - height[dad];
				long long ans = 0;
				for (int i = LN - 1; i >= 0; --i) {
					bool set = edges & (1 << i);
					if (set) {
						ans += dist[a][i];
						a = up[a][i];
					}
				}
				edges = height[b] - height[dad];
				for (int i = LN - 1; i >= 0; --i) {
					bool set = edges & (1 << i);
					if (set) {
						ans += dist[b][i];
						b = up[b][i];
					}
				}
				printf("%lld\n", ans);
			} else {
				int a, b, k;
				scanf("%d %d %d", &a, &b, &k);
				--k;
				int dad = lca(a, b);
				int edges = height[a] - height[dad];
				if (edges == k) {
					printf("%d\n", dad);
					continue;
				}
				if (edges > k) {
					for (int i = LN - 1; i >= 0; --i) {
						bool b = k & (1 << i);
						if (b) {
							a = up[a][i];
						}
					}
					printf("%d\n", a);
					continue;
				}
				int edges1 = height[b] - height[dad] - k + edges;
				if (edges1 <= 0) {
					printf("%d\n", b);
					continue;
				}
				for (int i = LN - 1; i >= 0; --i) {
					bool set = edges1 & (1 << i);
					if (set) {
						b = up[b][i];
					}
				}
				printf("%d\n", b);
			}
		}
		puts("");
	}
	return 0;
}