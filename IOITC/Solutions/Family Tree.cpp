// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 2;
const int LN = 21;

vector < int > g[N];
vector < int > h[N];
int up[N][LN];
int tin[N];
int tout[N];
int depth[N];
int pr[N];

int n;
int q;
int timer;

void dfs (int x, int p, int d) {
	tin[x] = ++timer;
	depth[x] = d;
	up[x][0] = p;
	h[depth[x]].emplace_back(timer);
	for (int i = 1; i < LN; ++i) {
		up[x][i] = up[up[x][i - 1]][i - 1];
	}
	for (int to : g[x]) {
		dfs(to, x, d + 1);
	}
	tout[x] = ++timer;
	h[depth[x]].emplace_back(timer);
}

inline int occ (int d, int l, int r) {
	return lower_bound(h[d].begin(), h[d].end(), r + 1) - lower_bound(h[d].begin(), h[d].end(), l);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", pr + i);
		if (!pr[i]) {
			continue;
		}
		g[pr[i]].emplace_back(i);
	}
	for (int i = 1; i <= n; ++i) {
		if (!pr[i]) {
			dfs(i, 0, 0);
		}
	}
	scanf("%d", &q);
	while (q--) {
		int x, p;
		scanf("%d %d", &x, &p);
		int start = x;
		for (int i = 0; i < LN; ++i) {
			if (p & (1 << i)) {
				x = up[x][i];
			}
		}
		if (!x) {
			puts("0");
			continue;
		}
		printf("%d\n", (occ(depth[start], tin[x], tout[x]) >> 1) - 1);
	}
	return 0;
}