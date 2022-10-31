// https://dmoj.ca/problem/lcs
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 1001;

int dp[N][N];
int a[N], b[N];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	} 
	for (int i = 1; i <= m; ++i) {
		scanf("%d", b + i);
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
			} else if (a[i] == b[j]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	printf("%d\n", dp[n][m]);
	return 0;
}