// http://codeforces.com/contest/689/problem/B

#include <bits/stdc++.h>

using namespace std;

const int N = 200010, oo = 1 << 30;

int z[N];
int d[N];
priority_queue < pair <int, int>, vector < pair <int, int> >, greater < pair <int, int> >> pq;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", z + i);
	}
	fill(d, d + n + 1, oo);
	d[1] = 0;
	pq.push({0, 1});
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		int v = u + 1;
		if (v <= n && d[v] > d[u] + 1) {
			d[v] = d[u] + 1;
			pq.push({d[v], v});
		}
		v = z[u];
		if (d[v] > d[u] + 1) {
			d[v] = d[u] + 1;
			pq.push({d[v], v});
		}
		v = u - 1;
		if (v >= 1 && d[v] > d[u] + 1) {
			d[v] = d[u] + 1;
			pq.push({d[v], v});
		}
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d ", d[i]);
	}
	return 0;
}