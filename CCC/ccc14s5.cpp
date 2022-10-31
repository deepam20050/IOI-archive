// https://dmoj.ca/problem/ccc14s5
// http://mmhs.ca/ccc/2014/2014s5jacobjackson.txt

#include <bits/stdc++.h>

using namespace std;

const int N = 2010;

int x[N], y[N], dp[N], pbest[N], dist[N];
pair < int , pair <int , int> > p[N * N];

int calc(int x, int y) {
	return x * x + y * y;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", x + i, y + i);
	}
	int sz = 0;
	for (int i = 0; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j, ++sz) {
			p[sz].first = calc(x[i] - x[j], y[i] - y[j]);
			p[sz].second.first = i;
			p[sz].second.second = j;
		}
	}
	sort(p, p + sz);
	for (int i = 0; i < sz; ++i) {
		int d = p[i].first;
		int u = p[i].second.first;
		int v = p[i].second.second;
		if (d != dist[u]) {
			dist[u] = d;
			pbest[u] = dp[u];
		}
		if (d != dist[v]) {
			dist[v] = d;
			pbest[v] = dp[v];
		}
		if (u == 0) {
			dp[0] = max(dp[u], dp[v]);
		} else {
			dp[u] = max(dp[u], pbest[v] + 1);
			dp[v] = max(dp[v], pbest[u] + 1);
		}
	}
	printf("%d", dp[0] + 1);
	return 0;
}