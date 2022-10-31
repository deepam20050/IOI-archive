// http://codeforces.com/contest/855/problem/C

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long mod = 1e9 + 7;

long long dp[N][3][12];
vector < int > g[N];
long long tmp[12];
int n;
int k;
int m;
int cnt;

void dfs (int x, int p) {
	for (int to : g[x]) {
		if (to != p) {
			dfs(to, x);
		}
	}
	dp[x][0][1] = 1;
	dp[x][1][0] = k - 1;
	dp[x][2][0] = m - k;
	// put node x = k
	for (int to : g[x]) {
		if (to == p) {
			continue;
		}
		memset(tmp, 0, sizeof tmp);
		for (int i = 0; i <= cnt; ++i) {
			for (int j = cnt; j >= i; --j) {
				tmp[j] = (tmp[j] + dp[to][1][i] * dp[x][0][j - i] % mod) % mod;
			}
		}
		for (int i = 0; i <= cnt; ++i) {
			dp[x][0][i] = tmp[i];
		}
	}
	// put node x <= k - 1
	for (int to : g[x]) {
		if (to == p) {
			continue;
		}
		memset(tmp, 0, sizeof tmp);
		for (int i = 0; i <= cnt; ++i) {
			for (int j = cnt; j >= i; --j) {
				tmp[j] = (tmp[j] + (dp[to][0][i] + dp[to][1][i] + dp[to][2][i]) % mod * dp[x][1][j - i]) % mod;
			}
		}
		for (int i = 0; i <= cnt; ++i) {
			dp[x][1][i] = tmp[i];
		}
	}
	// put node x >= m - k
	for (int to : g[x]) {
		if (to == p) {
			continue;
		}
		memset(tmp, 0, sizeof tmp);
		for (int i = 0; i <= cnt; ++i) {
			for (int j = cnt; j >= i; --j) {
				tmp[j] = (tmp[j] + (dp[to][1][i] + dp[to][2][i]) % mod * dp[x][2][j - i] % mod) % mod;
			}
		}
		for (int i = 0; i <= cnt; ++i) {
			dp[x][2][i] = tmp[i];
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i < n; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		g[x].emplace_back(y);
		g[y].emplace_back(x);
	}
	scanf("%d %d", &k, &cnt);
	dfs(1, 0);
	int ans = 0;
	for (int i = 0; i <= cnt; ++i) {
		for (int type = 0; type <= 2; ++type) {
			ans += dp[1][type][i];
			// cout << "i -> " << i << " type -> " << type << " " << dp[1][type][i] << '\n';
			if (ans >= mod) {
				ans -= mod;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}