// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector < pair < int, int > > g[N];
bool used[N];
int val[N];
int n;
int m;
int k;

void dfs (int x, int what) {
	used[x] = 1;
	val[x] = what;
	for (auto &e : g[x]) {
		int to = e.first;
		int w = e.second;
		if (used[to] && (val[to] ^ what) != w) {
			puts("-1");
			exit(0);
		}
		if (!used[to]) {
			dfs(to, w ^ what);
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; ++i) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		g[x].push_back({y, z});
		g[y].push_back({x, z});
	}
	int lst;
	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			dfs(i, 0);
			lst = i;
		}
	}
	memset(used, 0, sizeof used);
	dfs(lst, k - 1);
	for (int i = 1; i <= n; ++i) {
		printf("%d ", val[i]);
	}
	return 0;
}