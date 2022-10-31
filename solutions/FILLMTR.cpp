// https://www.codechef.com/problems/FILLMTR

#include "bits/stdc++.h"

using namespace std;

const int N = 100010;

vector < pair <int, int> > g[N];
int color[N];
bool ok;

void dfs (int x) {
	for (auto &e: g[x]) {
		int to = e.first;
		if (color[to] == -1) {
			color[to] = color[x] ^ e.second;
			dfs(to);
		} else if (color[to] ^ e.second ^ color[x]) {
			ok = 0;
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, q;
		scanf("%d %d", &n, &q);
		for (int i = 1; i <= n; ++i) {
			color[i] = -1;
			g[i].clear();
		}
		while (q--) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			g[x].push_back({y, z});
			g[y].push_back({x, z});
		}
		ok = 1;
		for (int i = 1; i <= n; ++i) {
			if (color[i] == -1) {
				color[i] = 0;
				dfs(i);
			}
		}
		ok ? puts("yes") : puts("no");
	}
	return 0;
}