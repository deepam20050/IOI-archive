// http://www.spoj.com/problems/TRT/

#include <bits/stdc++.h>

using namespace std;

const int N = 2010;

int dp[N][N], a[N];

int n;

int solve (int l, int r, int day) {
	if (l > r || day > n) {
		return 0;
	}
	if (dp[l][r] != -1) {
		return dp[l][r];
	}
	int mx1 = solve(l + 1, r, day + 1) + a[l] * day;
	int mx2 = solve(l, r - 1, day + 1) + a[r] * day;
	return dp[l][r] = max(mx1, mx2);
}

int main() {
	memset(dp, -1, sizeof dp);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	printf("%d\n", solve(0, n - 1, 1));
	return 0;
}