// http://codeforces.com/problemset/problem/545/E

#include <bits/stdc++.h>

using namespace std;
using pi = pair <long long, int>;

const int N = 300010;
const long long oo = 1LL << 60;

vector <pi> g[N];
long long d[N];
priority_queue <pi, vector <pi>, greater <pi>> pq;
long long weight[N];
set <int> vv;
long long edge[N];
int p[N];
map <pi, int> mp;

void add(int u, int v, int idx) {
	if (u > v) {
		swap(u, v);
	}
	mp[{u, v}] = idx;
}

int query(int u, int v) {
	if (u > v) {
		swap(u, v);
	}
	return mp[{u, v}];
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		d[i] = oo;
		edge[i] = oo;
	}
	for (int i = 1; i <= m; ++i) {
		int x, y;
		long long z;
		scanf("%d %d %lld", &x, &y, &z);
		g[x].push_back({y, z});
		g[y].push_back({x, z});
		weight[i] = z;
		add(x, y, i);
	}
	int x;
	scanf("%d", &x);
	d[x] = 0;
	p[x] = -1;
	pq.push({0, x});
	while (!pq.empty()) {
		int u = pq.top().second;
		if (p[u] != -1) {
			vv.insert(query(u, p[u]));
		}
		pq.pop();
		for (auto to: g[u]) {
			int v = to.first, w = to.second;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				edge[v] = w;
				p[v] = u;
				pq.push({d[v], v});
			} else if (d[v] == d[u] + w && edge[v] > w) {
				edge[v] = w;
				p[v] = u;
			}
		}
	}
	long long sum = 0;
	for (int e: vv) {
		sum += weight[e];
	}
	printf("%lld\n", sum);
	for (int e: vv) {
		printf("%d ", e);
	}
	return 0;
}