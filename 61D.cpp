// http://codeforces.com/problemset/problem/61/D

#include <bits/stdc++.h>

using namespace std;
using pi = pair <long long, int>;

const int N = 100010;

vector < pair <int, int>> g[N];
priority_queue <pi, vector <pi>, greater <pi>> pq;
long long d[N];
bool used[N];

long long dfs(int x) {
	long long ans = 0;
	used[x] = 1;
	for (auto to: g[x]) {
		if (!used[to.first]) {
			ans += to.second + dfs(to.first);
		}
	}
	return ans;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		g[x].push_back({y, z});
		g[y].push_back({x, z});
	}
	pq.push({0, 1});
	for (int i = 0; i <= n; ++i) {
		d[i] = 1LL << 60;
	}
	d[1] = 0;
	while (!pq.empty()) {
		int x = pq.top().second;
		pq.pop();
		for (auto to: g[x]) {
			if (d[to.first] > d[x] + to.second) {
				d[to.first] = d[x] + to.second;
				pq.push({d[to.first], to.first});
			}
		}
	}
	long long mx = -1;
	for (int i = 1; i <= n; ++i) {
		if (d[i] != 1LL << 60) {
			mx = max(mx, d[i]);
		}
	}
	long long ans = dfs(1) - mx;
	printf("%lld", ans + ans + mx);
	return 0;
}