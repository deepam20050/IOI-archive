// http://codeforces.com/problemset/problem/118/D
// AC
// Awesome DP

#include <bits/stdc++.h>

using namespace std;

const int N = 210;
const long mod = 1e8; 

long dp[N][N][2]; 

int main() {
	int n, m, k1, k2;
	scanf("%d %d %d %d", &n, &m, &k1, &k2);
	
	for (int i = 1; i <= k1; ++i) {
		dp[i][0][0] = 1;
	}
	for (int i = 1; i <= k2; ++i) {
		dp[0][i][1] = 1;
	}

	for (int s = 1; s <= n; ++s) {
		for (int a = 1; a <= m; ++a) {
			for (int i = 1; i <= min(k1, n) && s - i >= 0; ++i) {
				dp[s][a][0] += dp[s - i][a][1];
				dp[s][a][0] %= mod;
			}

			for (int i = 1; i <= min(k2, m) && a - i >= 0; ++i) {
				dp[s][a][1] += dp[s][a - i][0];
				dp[s][a][1] %= mod;
			}
		}
	}

	printf("%ld\n", (dp[n][m][1] + dp[n][m][0]) % mod);

	return 0;
}