// http://codeforces.com/contest/859/problem/C

#include "bits/stdc++.h"

using namespace std;

const int N = 51;

int a[N];
int dp[N][2];

int n;

int solve (int pie, int token) {
	if (pie > n) {
		return 0;
	}
	if (dp[pie][token] != -1) {
		return dp[pie][token];
	}
	if (token) {
		dp[pie][token] = max(a[pie] + solve(pie + 1, token ^ 1), solve(pie + 1, token));
	} else {
		dp[pie][token] = min(solve(pie + 1, token) + a[pie], solve(pie + 1, token ^ 1));
	}
	return dp[pie][token];
}

int main() {
	int sum = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		sum += a[i];
	}
	memset(dp, -1, sizeof dp);
	solve(1, 1);
	printf("%d %d", sum - dp[1][1], dp[1][1]);
	return 0;
}