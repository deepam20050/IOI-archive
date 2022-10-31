// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 122;
const int MOD = 1e9 + 7;

int arr[N];
int dp[N][N];
int n;

int mod (int &x) {
	if (x >= MOD) {
		x -= MOD;
	}
}

int f (int l, int r) {
	if (l >= r) {
		return 1;
	}
	if (dp[l][r] != -1) {
		return dp[l][r];
	}
	dp[l][r] = f(l + 1, r);
	if (arr[l] > 0) {
		return dp[l][r];
	}
	for (int i = l + 1; i <= r; ++i) {
		if (-arr[l] == arr[i]) {
			dp[l][r] += 1LL * f(l + 1, i - 1) * f(i + 1, r) % MOD;
			mod(dp[l][r]);
		}
	}
	return dp[l][r];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", arr + i);
	}
	memset(dp, -1, sizeof dp);
	printf("%d\n", f(1, n));
	return 0;
}