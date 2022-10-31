// http://codeforces.com/contest/682/problem/C

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

vector < pair <int, int > > g[N];
int a[N];

int ans;

int dfs (int node, int parent, long long dist, long long mini, bool rem) {
	mini = min(mini, dist);
	if (dist - mini > a[node]) {
		rem = 1;
	}
	ans += rem;
	for (auto to: g[node]) {
		if (to.first != parent) {
			dfs (to.first, node, dist + to.second, mini, rem);
		}
	}
	return ans;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	for (int i = 2; i <= n; ++i) {
		int p, c;
		scanf("%d %d", &p, &c);
		g[p].push_back({i, c});
		g[i].push_back({p, c});
	}
	printf("%d\n", dfs(1, 0, 0, 0, 0));
	return 0;
}