// https://www.codechef.com/LTIME61

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

pair < int, int > g[N];
int mx[N];
int mi[N];

int dfs (int x) {
	if (g[x].first == -1) {
		mx[x] = g[x].second;
		mi[x] = g[x].second;
		return 0;
	}
	int lft = g[x].first;
	int rgt = g[x].second;
	int ans_lft = dfs(lft);
	int ans_rgt = dfs(rgt);
	mx[x] = max(mx[lft], mx[rgt]);
	mi[x] = min(mi[lft], mi[rgt]);
	if (ans_lft == -1 || ans_rgt == -1) {
		return -1;
	}
	if (mx[lft] < mi[rgt]) {
		return ans_lft + ans_rgt;
	} else if (mi[lft] > mx[rgt]) {
		return ans_lft + ans_rgt + 1;
	}
	return -1;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			int l, r;
			scanf("%d %d", &l, &r);
			g[i] = {l, r};
		}
		printf("%d\n", dfs(1));
	}
	return 0;
}