// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 1;
const int MOD = 1E9 + 7;

int dp[N][N];
int sum[N][N];
int tmp[N];
int sum_all[N];

inline void mod (int &x) {
	if (x >= MOD) {
		x -= MOD;
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int x = 1; x <= m; ++x) {
		sum[x][1] = 1;
		sum_all[x] = x;
		dp[x][1] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		dp[1][i] = 1;
		sum[1][i] = 1;
	}
	for (int i = 2; i <= n; ++i) {
		tmp[1] = 1;
		for (int x = 2; x <= m; ++x) {
			dp[x][i] = sum_all[x - 1];
			sum[x][i] = sum[x][i - 1] + dp[x][i];
			mod(sum[x][i]);
			tmp[x] = tmp[x - 1] + sum[x][i];
			mod(tmp[x]); 
		}
		for (int x = 2; x <= m; ++x) {
			sum_all[x] = tmp[x];
		}
	}
	int ans = 1;
	for (int i = 1; i <= n; ++i) {
		for (int x = 2; x <= m; ++x) {
			int add = dp[x][n - i + 1] + sum[x][n - i];
			mod(add);
			ans += 1LL * dp[x][i] * add %	MOD;
			mod(ans);
		}
	}
	printf("%d\n", ans);
	return 0;
}	