#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;
const int SZ = 3e5 + 2;

int tin[N];
bool used[N];
int fup[N];
int depth[N];
int pr[N];
vector < int > g[N];

bool good;
int n;
int m;
int timer;
int tc;

void find_bridges (int x, int p, int d = 0) {
	tin[x] = ++timer;
	used[x] = 1;
	fup[x] = tin[x];
	depth[x] = d;
	for (int to : g[x]) {
		if (to == p) {
			continue;
		}
		if (used[to]) {
			fup[x] = min(fup[x], tin[to]);
		} else {
			find_bridges(to, x, d + 1);
			fup[x] = min(fup[x], fup[to]);
		}
	}
}

inline void back_track (int fst, int lst) {
	puts("2");
	int x = lst;
	while (x != fst) {
		printf("%d ", x);
		x = pr[x];
	}
	printf("%d %d\n", x, lst);
}

void good_cycle (int x, int p, int cnt = 0) {
	if (good) {
		return;
	}
	used[x] = 1;
	for (int to : g[x]) {
		if (good) {
			return;
		}
		if (to == p) {
			continue;
		}
		if (used[to] && ((depth[x] - depth[to] + 1) & 1) && !cnt) {
			back_track(to, x);
			good = 1;
			return;
		} else {
			if (good) {
				return;
			}
			pr[to] = x;
			good_cycle(to, x, (fup[to] > tin[x]) + cnt);
			if (good) {
				return;
			}
		}
		if (good) {
			return;
		}
	}
}


int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			used[i] = 0;
			g[i].clear();
		}
		timer = 0;
		good = 0;
		for (int i = 0, x, y; i < m; ++i) {
			scanf("%d %d", &x, &y);
			g[x].emplace_back(y);
			g[y].emplace_back(x);
		}
		find_bridges(1, 0);
		memset(used, 0, sizeof used);
		good_cycle(1, 0);
	}
	return 0;
}