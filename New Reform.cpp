// http://codeforces.com/problemset/problem/659/E
// AC
// very good problem

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

vector <int> g[N];
bool used[N];

void dfs(int x, int &val, int &nodes) {
	used[x] = 1;
	val += g[x].size();
	++nodes;
	for (const auto &e: g[x]) {
		if (!used[e]) {
			dfs(e, val, nodes);
		}
	}
}

int main() {
	int n,m;
	scanf("%d %d",&n,&m);

	for (int i = 0; i < m; ++i) {
		int x,y;
		scanf("%d %d",&x,&y);
		g[x].emplace_back(y);
		g[y].emplace_back(x);
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			int e = 0, nodes = 0;
			dfs(i, e, nodes);
			e /= 2;
			if (e == nodes - 1) ++ans;
		}
	}	

	printf("%d\n",ans);
	
	return 0;
}