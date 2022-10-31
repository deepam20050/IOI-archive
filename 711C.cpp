// http://codeforces.com/problemset/problem/711/C

#include "bits/stdc++.h"

using namespace std;

const int N = 110;
const long long oo = 1e15;

long long dp[N][N][N];
int cost[N][N];
int a[N];

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= k; ++j) {
			for (int c = 0; c <= m; ++c) {
				dp[i][j][c] = oo;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &cost[i][j]);
		}
	}
	if (a[1] == 0) {
		for (int i = 1; i <= m; ++i) {
			dp[1][1][i] = cost[1][i];
		}
	} else {
		dp[1][1][a[1]] = 0;
	}
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			if (a[i] == 0) {
				for (int c = 1; c <= m; ++c) {
					dp[i][j][c] = min(dp[i][j][c], dp[i - 1][j][c] + cost[i][c]);
					for (int d = 1; d <= m; ++d) {
						if (d != c) {
							dp[i][j][c] = min(dp[i][j][c], dp[i - 1][j - 1][d] + cost[i][c]);
						}
					}
				}
			} else {
				dp[i][j][a[i]] = min(dp[i][j][a[i]], dp[i - 1][j][a[i]]);
				for (int d = 1; d <= m; ++d) {
					if (d != a[i]) {
						dp[i][j][a[i]] = min(dp[i][j][a[i]], dp[i - 1][j - 1][d]);
					}
				}
			}
		}
	}
	long long ans = oo;
	for (int i = 1; i <= m; ++i) {
		ans = min(ans, dp[n][k][i]);
	}
	ans >= oo ? puts("-1") : printf("%lld\n", ans);
	return 0;
}