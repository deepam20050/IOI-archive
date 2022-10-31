// http://www.spoj.com/problems/DISQUERY/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int LN = 18;

vector < pair < int, int > > g[N];
int tin[N];
int tout[N];
int height[N];
int up[N][LN];
int mx[N][LN];
int mi[N][LN];
int timer;
int n;
int q;

inline void dfs1 (int x, int p, int depth = 0, int up0_mx = -1, int up0_min = 2e9) {
	tin[x] = ++timer;
	height[x] = depth;
	up[x][0] = p;
	mx[x][0] = up0_mx;
	mi[x][0] = up0_min;
	for (int i = 1; i < LN; ++i) {
		up[x][i] = up[up[x][i - 1]][i - 1];
		mx[x][i] = max(mx[x][i - 1], mx[up[x][i - 1]][i - 1]);
		mi[x][i] = min(mi[x][i - 1], mi[up[x][i - 1]][i - 1]);
	}
	for (auto &e : g[x]) {
		int to = e.first;
		int weight = e.second;
		if (to == p) {
			continue;
		}
		dfs1(to, x, depth + 1, weight, weight);
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
	for (int i = 0; i < LN; ++i) {
		mx[0][i] = -1;
		mi[0][i] = 2e9;
	}
	tin[0] = -1;
	tout[0] = 2e9;
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		g[x].push_back({y, z});
		g[y].push_back({x, z});
	}
	dfs1(1, 0);
	scanf("%d", &q);
	while (q--) {
		int x, y;
		scanf("%d %d", &x, &y);
		int dad = lca(x, y);
		int edges = height[x] - height[dad];
		int ans_mx = -1;
		int ans_mi = 2e9;
		for (int i = LN - 1; i >= 0; --i) {
			bool b = edges & (1 << i);
			if (b) {
				ans_mx = max(ans_mx, mx[x][i]);
				ans_mi = min(ans_mi, mi[x][i]);
				x = up[x][i];
			}
		}
		edges = height[y] - height[dad];
		for (int i = LN - 1; i >= 0; --i) {
			bool b = edges & (1 << i);
			if (b) {
				ans_mx = max(ans_mx, mx[y][i]);
				ans_mi = min(ans_mi, mi[y][i]);
				y = up[y][i];
			}
		}
		printf("%d %d\n", ans_mi, ans_mx);
	}
	return 0;
}