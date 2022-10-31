// http://codeforces.com/contest/577/problem/B

#include "bits/stdc++.h"

using namespace std;

const int N = 1234, M = 1000010;

bool dp[N][N];
int a[M];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	if (n >= m) {
		return !printf("YES");
	} 
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		a[i] %= m;
	}
	for (int i = 0; i < n; ++i) {
		dp[i][a[i]] = 1;
		for (int j = 0; j < m; ++j) {
			dp[i][j] |= dp[i - 1][j];
			dp[i][j] |= dp[i - 1][(j - a[i] + m) % m];
		}
	}
	dp[n - 1][0] ? puts("YES") : puts("NO");
	return 0;
}