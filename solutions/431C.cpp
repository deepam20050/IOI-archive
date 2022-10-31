// http://codeforces.com/contest/431/problem/C
// AC 
// Very good problem on DP

#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int dp[100][2];

int main() {
	int n,k,d;
	scanf("%d %d %d",&n,&k,&d);

	dp[0][0] = 1;
	dp[0][1] = 0;

	for (int i = 1; i <= n; ++i) {
		dp[i][0] = dp[i][1] = 0;
		for (int j = 1; j <= k; ++j) {
			if (i - j < 0) break;

			if (j >= d) {
				dp[i][1] = (dp[i][1] + dp[i-j][1]) % mod;
				dp[i][1] = (dp[i][1] + dp[i-j][0]) % mod;
			} else {
				dp[i][0] = (dp[i][0] + dp[i-j][0]) % mod;
				dp[i][1] = (dp[i][1] + dp[i-j][1]) % mod;
			}
		}
	}

	printf("%d\n",dp[n][1]);

	return 0;
}