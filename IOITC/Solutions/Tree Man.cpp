#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long MOD = 1e9 + 7;

vector < int > g[N];
long long dp[N][2];
long long subtree[N];

int n;
long long ans;
 
inline void mod (long long &x) {
	x %= MOD;
	x += MOD;
	x %= MOD;
}

void dfs (int x) {
	long long sum = 0;
	for (int to : g[x]) {
		dfs(to);
		subtree[x] += subtree[to];
		dp[x][0] += dp[to][0];
		dp[x][1] += dp[to][1];
		mod(dp[x][0]);
		mod(dp[x][1]);
	}
	for (int to : g[x]) {
		sum += ((subtree[x] - subtree[to]) * subtree[to]) % MOD;
		mod(sum); 
	}
	dp[x][0] += sum >> 1LL;
	mod(dp[x][0]);
	for (int to : g[x]) {
		sum -= (2LL * (subtree[x] - subtree[to]) * subtree[to]) % MOD;
		mod(sum);
		dp[x][1] += ((sum >> 1LL) * dp[to][0]) % MOD;
		mod(dp[x][1]);
		sum += (2LL * (subtree[x] - subtree[to]) * subtree[to]) % MOD;
		mod(sum);
		ans += dp[to][1];
		mod(ans);
	}
	++subtree[x];
}

int main() {
	scanf("%d", &n);
	for (int i = 1, pr; i <= n; ++i) {
		scanf("%d", &pr);
		g[pr].emplace_back(i);
	}
	dfs(0);
	printf("%lld", ans);
	return 0;
}