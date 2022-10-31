// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector < int > g[N];
int tin[N];
int tout[N];
int timer;
int n;
int q;
long long bit[N + N];

void dfs (int x, int p) {
	tin[x] = ++timer;
	for (int to : g[x]) {
		if (to != p) {
			dfs(to, x);
		}
	}
	tout[x] = ++timer;
}

inline void update (int idx, int add) {
	while (idx < timer) {
		bit[idx] += 1LL * add;
		idx += idx & -idx;
	}
}

inline long long query (int idx) {
	long long ret = 0LL;
	while (idx) {
		ret += bit[idx];
		idx -= idx & -idx;
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		g[x].emplace_back(y);
		g[y].emplace_back(x);
	}
	dfs(0, - 1);
	scanf("%d", &q);
	while (q--) {
		char op;
		cin >> op;
		if (op == 'A') {
			int x, inc;
			scanf("%d %d", &x, &inc);
			update(tin[x], inc);
			update(tout[x], -inc);
		} else {
			int x;
			scanf("%d", &x);
			printf("%lld\n", query(tin[x]));
		}
	}
	return 0;
}