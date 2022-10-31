// http://codeforces.com/problemset/problem/691/D

#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

vector <int> g[N];
bool used[N];
int p[N], a[N];
vector <int> val, pos;

void dfs(int x) {
	used[x] = 1;
	for (int to: g[x]) {
		if (!used[to]) {
			val.emplace_back(p[to]);
			pos.emplace_back(to);
			dfs(to);
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", p + i);
	}
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			pos.clear();
			val.clear();
			pos.emplace_back(i);
			val.emplace_back(p[i]);
			dfs(i);
			sort(pos.begin(), pos.end());
			sort(val.begin(), val.end(), greater <int> ());
			for (int i = 0, sz = pos.size(); i < sz; ++i) {
				a[pos[i]] = val[i];
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d ", a[i]);
	}
	return 0;
}