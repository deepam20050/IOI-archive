// https://dmoj.ca/problem/ccc07s4
// AC

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 10010;

vector <int> g[N];
ll dp[N];
bool used[N];

ll dfs(int x) {
	used[x] = 1;

	for (const auto &e: g[x]) {
		if (!used[e]) {
			dfs(e);
		}
		dp[x] += dp[e];
	}
	return dp[x];
}

int main() {
	int n;
	scanf("%d",&n);

	int x, y;
	while (scanf("%d %d", &x, &y) && x != 0 && y != 0) {
		g[x].emplace_back(y);
	}

	dp[n] = 1;
	printf("%lld\n",dfs(1));

	return 0;
}