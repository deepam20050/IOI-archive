// https://www.codechef.com/problems/COUPON

#include "bits/stdc++.h"
 
using namespace std;
 
const long long oo = 1e18;
 
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		long long c[n + 2][m + 2], d[n + 2][m + 2];
		memset(c, 0, sizeof c);
		long long dp[n + 2][m + 2];
		memset(dp, 0, sizeof dp);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				scanf("%lld", &c[i][j]);
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				scanf("%lld", &d[i][j]);
			}
		}
		long long abtak = oo;
		for (int i = n; i >= 1; --i) {
			long long t = oo;
			for (int j = 1; j <= m; ++j) {
				dp[i][j] = max(c[i + 1][j] - d[i][j], 0LL) + dp[i + 1][j] - c[i + 1][j];
				dp[i][j] = min(dp[i][j], abtak);
				dp[i][j] += c[i][j];
				t = min(t, dp[i][j]);
			}
			abtak = t;
		}
		long long ans = oo;
		for (int i = 1; i <= m; ++i) {
			ans = min(ans, dp[1][i]);
		}	
		printf("%lld\n", ans);
	}
	return 0;
} 