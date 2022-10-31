#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int LN = 18;

int tin[N];
int tin_tree[N];
int tout_tree[N];
bool used[N];
int fup[N];
int color[N];
int p[N];
int up[N][LN];
pair < int, int > store[N];
char res[N];
vector < int > g[N];
vector < int > tree[N];
unordered_map < int, int > bridge[N];
unordered_map < int, int > edge[N];
unordered_map < int, int > tree_edge[N];
int timer;
int n;
int m;
int bridge_idx;
int cities;

inline void find_bridges (int x, int p) {
	tin[x] = fup[x] = ++timer;
	used[x] = 1;
	for (int to : g[x]) {
		if (to == p) {
			continue;
		}
		if (used[to]) {
			fup[x] = min(fup[x], tin[to]);
		} else {
			find_bridges(to, x);
			fup[x] = min(fup[to], fup[x]);
			if (fup[to] > tin[x]) {
				bridge[x][to] = 1;
				bridge[to][x] = 1;
				store[bridge_idx++] = {x, to};
			}
		}
	}
}

inline void discover_component (int x, int c) {
	used[x] = 1;
	color[x] = c;
	for (int to : g[x]) {
		if (!used[to] && !bridge[x][to]) {
			discover_component(to, c);
		}
		if (bridge[x][to]) {
			tree_edge[color[x]][color[to]] = max(edge[x][to], edge[to][x]);
			tree_edge[color[to]][color[x]] = max(edge[x][to], edge[to][x]);
		}
	}
}

inline void dfs (int x, int pr) {
	tin_tree[x] = ++timer;
	up[x][0] = pr;
	for (int i = 1; i < LN; ++i) {
		up[x][i] = up[up[x][i - 1]][i - 1];
	}
	// cout << x << '\n';
	for (int to : tree[x]) {
		if (to != pr) {
			p[to] = x;
			dfs(to, x);
		}
	}
	tout_tree[x] = ++timer;
}

inline bool is_ancestor (int x, int y) {
	return tin_tree[x] <= tin_tree[y] && tout_tree[x] >= tout_tree[y];
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
	memset(res, 'B', sizeof res);
	scanf("%d %d", &n, &m);
	for (int i = 0, u, v; i < m; ++i) {
		scanf("%d %d", &u, &v);
		g[u].emplace_back(v);
		g[v].emplace_back(u);
		edge[u][v] = i + 1;
	}
	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			find_bridges(i, -1);
		}
	}
	memset(used, 0, sizeof used);
	int x, y;
	for (int i = 0; i < bridge_idx; ++i) {
		x = store[i].first;
		y = store[i].second;
		if (!used[x]) {
			discover_component(x, x);
		}
		if (!used[y]) {
			discover_component(y, y);
		}
		tree[color[x]].emplace_back(color[y]);
		tree[color[y]].emplace_back(color[x]);
	}
	timer = 0;
	tin_tree[0] = -1;
	tout_tree[0] = 2e9;
	for (int i = 1; i <= n; ++i) {
		if (!color[i]) {
			dfs(i, i);
		}
	}
	scanf("%d", &cities);
	for (int i = 0; i < cities; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		if (color[x] == color[y]) {
			continue;
		}
		int dad = lca(color[x], color[y]);
		// cout << dad << '\n';
		int curr = x;
		while (curr != dad) {
			int papa = p[curr];
			if (res[tree_edge[papa][curr]] != 'B' || res[tree_edge[curr][papa]] != 'B') {
				break;
			}
			if (tree_edge[papa][curr]) {
				res[tree_edge[papa][curr]] = 'R';
			} else {
				res[tree_edge[curr][papa]] = 'L';
			}
			curr = papa;
		}
		curr = y;
		while (curr != dad) {
			int papa = p[curr];
			if (res[tree_edge[papa][curr]] != 'B' || res[tree_edge[curr][papa]] != 'B') {
				break;
			}
			if (tree_edge[papa][curr]) {
				res[tree_edge[papa][curr]] = 'L';
			} else {
				res[tree_edge[curr][papa]] = 'R';
			}
			curr = papa;
		}
	}
	for (int i = 1; i <= m; ++i) {
		putchar(res[i]);
	}
	return 0;
}