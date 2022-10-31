// https://dmoj.ca/problem/ccc00s4
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 5281, inf = 1e4;

int dp[N][101];
int c[N];

int main() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 101; ++j) {
			dp[i][j] = inf;
		}
	}
	int l;
	scanf("%d", &l);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", c + i);
	}
	for (int i = 1; i <= l; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i - c[j] == 0) {
				dp[i][j] = 1;
			} else if (i - c[j] > 0) {
				dp[i][j] = min(dp[i][j - 1], 1 + dp[i - c[j]][j]);
			} else {
				dp[i][j] = dp[i][j - 1];
			}
		}
	}
	if (dp[l][n] >= inf) {
		puts("Roberta acknowledges defeat.");
	} else {
		printf("Roberta wins in %d strokes.\n", dp[l][n]);
	}
	return 0;
}