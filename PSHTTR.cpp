// https://www.codechef.com/problems/PSHTTR

#include "bits/stdc++.h"

using namespace std;

const int N = 100010;

vector <int> g[N];
int st[N], en[N], bit[N];
pair <int, int> edge[N];
int w[N], ans[N], q1[N], q2[N];

int n, timer;

void add (int idx, int val) {
	while (idx <= n) {
		bit[idx] ^= val;
		idx += idx & (-idx);
	}
}

int get(int idx) {
	int ans = 0;
	while (idx > 0) {
		ans ^= bit[idx];
		idx -= idx & (-idx);
	}
	return ans;
}

void dfs (int x, int p) {
	st[x] = ++timer;
	for (int to : g[x]) {
		if (to != p) {
			dfs(to, x);
		}
	}
	en[x] = timer;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		for (int i = 0; i < N; ++i) {
			bit[i] = 0;
			g[i].clear();
		}
		scanf("%d", &n);
		for (int i = 1; i < n; ++i) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			g[a].push_back(b);
			g[b].push_back(a);
			edge[i] = {a, b};
			w[i] = c;
		}
		timer = 0;
		dfs(1, -1);
		vector < pair <int, int> > sorted;
		for (int i = 1; i < n; ++i) {
			if (st[edge[i].first] < st[edge[i].second]) {
				swap(edge[i].first, edge[i].second);
			}
			sorted.push_back({w[i], -edge[i].first});
		}
		int q;
		scanf("%d", &q);
		for (int i = 1; i <= q; ++i) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			q1[i] = a;
			q2[i] = b;
			sorted.push_back({c, i});
		}
		sort(sorted.begin(), sorted.end());
		for (const auto &e: sorted) {
			if (e.second < 0) {
				add(st[-e.second], e.first);
				add(en[-e.second] + 1, e.first);
			} else {
				ans[e.second] = get(st[q1[e.second]]) ^ get(st[q2[e.second]]);
			}
		}
		for (int i = 1; i <= q; ++i) {
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}