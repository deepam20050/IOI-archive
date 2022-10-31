// http://codeforces.com/problemset/problem/414/B
// AC
// Good problem on dp

#include <bits/stdc++.h>

using namespace std;

const int N = 2010;
const long mod = 1e9 + 7;

long dp[N][N];

int main() {
	int n,k;
	scanf("%d %d",&n,&k);

	for (int i = 1; i <= n; ++i) {
		dp[i][1] = 1;
	}

	for (int i = 2; i <= k; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int m = 1; j * m < N; ++m) {
				dp[j * m][i] += dp[j][i - 1];
				dp[j * m][i] %= mod;
			}
		}
	}

	long ans = 0;

	for (int i = 1; i <= n; ++i) {
		ans = (ans + dp[i][k]) % mod;
	}

	printf("%ld\n",ans);

	return 0;
}
