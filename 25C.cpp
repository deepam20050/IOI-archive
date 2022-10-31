// http://codeforces.com/problemset/problem/25/C
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 301;

int dp[N][N];
int sum[N];

int main() {
	int n;
	scanf("%d",&n);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d",&dp[i][j]);
		}
	}

	int k;
	scanf("%d",&k);

	for (int w = 0; w < k; ++w) {
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		dp[a][b] = dp[b][a] = min(dp[a][b], c);

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				dp[i][j] = min(dp[i][j], min(dp[i][a] + dp[a][b] + dp[b][j], dp[i][b] + dp[a][b] + dp[a][j]));
			}
		}
		long long ans = 0;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				ans += dp[i][j];
		printf("%lld ",ans/2);
	}

	return 0;
}
