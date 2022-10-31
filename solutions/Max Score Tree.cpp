// https://csacademy.com/contest/archive/task/max-score-tree/statement/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector < int > g[N];
long long score[N];
long long dp[N];
long long ans;
int n;

void dfs (int x, int p = -1) {
	dp[x] = score[1];
	vector < long long > vals;
	for (int to : g[x]) {
		if (to == p) {
			continue;
		}
		dfs(to, x);
		vals.emplace_back(dp[to]);
	}
	sort(vals.rbegin(), vals.rend());
	long long sum = 0;
	for (int i = 0; i < vals.size(); ++i) {
		sum += vals[i];
		ans = max(ans, 1LL * score[i + 1] + sum);
		dp[x] = max(dp[x], 1LL * score[i + 2] + sum);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", score + i);
	}
	ans = score[0];
	for (int i = 1; i < n; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		g[x].emplace_back(y);
		g[y].emplace_back(x);
	}
	dfs(1);
	printf("%lld", ans);
	return 0;
}