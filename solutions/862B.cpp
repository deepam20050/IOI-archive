// http://codeforces.com/contest/862/problem/B

#include "bits/stdc++.h"

using namespace std;

const int N = 100010;

int c[N];
int dost[N];
bool used[N];
vector <int> g[N];

void dfs (int x, int color) {
	used[x] = 1;
	c[x] = color;
	for (int to: g[x]) {
		if (!used[to]) {
			++dost[x];
			dfs(to, color ^ 1);
		} else {
			++dost[x];
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		g[x].emplace_back(y);
		g[y].emplace_back(x);
	}
	memset(c, -1, sizeof c);
	dfs(1, 1);
	long long odd = 0, even = 0;
	for (int i = 1; i < N; ++i) {
		if (c[i] == -1) {
			continue;
		}
		if (c[i] & 1) {
			++odd;
		} else {
			++even;
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (c[i] != -1) {
			if (c[i] == 0) {
				ans += max(0LL, odd - dost[i]);
			} else {
				ans += max(0LL, even - dost[i]);
			}
		}
	}
	printf("%lld", ans >> 1);
	return 0;
}