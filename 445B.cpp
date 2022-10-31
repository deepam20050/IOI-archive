// http://codeforces.com/problemset/problem/445/B
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 51;

vector <int> g[N];
bool used[N];

long long ans = 1;

void dfs(int x) {
	used[x] = 1;

	for (const auto &e: g[x]) {
		if (!used[e]) {
			ans *= 2;
			dfs(e);
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

	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			dfs(i);
		}
	}

	printf("%lld\n",ans);

	return 0;
}