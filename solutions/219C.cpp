// http://codeforces.com/problemset/problem/219/C

#include <bits/stdc++.h>

using namespace std;

const int N = 500010, INF = 1e9;

int dp[N][26], peche[N][26];
char s[N], res[N];

int main() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 26; ++j) {
			dp[i][j] = INF;
		}
	}
	int n, k;
	scanf("%d %d", &n, &k);
	scanf("%s", s);
	for (int i = 0; i < 26; ++i) {
		if (s[0] - 'A' == i) {
			dp[0][i] = 0;
		} else {
			dp[0][i] = 1;
		}
		peche[0][i] = -1;
	}
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			if (s[i] - 'A' == j) {
				for (int l = 0; l < k; ++l) {
					if (l != j) {
						if (dp[i - 1][l] < dp[i][j]) {
							peche[i][j] = l;
							dp[i][j] = dp[i - 1][l];
						}
					} 
				}
			} else {
				for (int l = 0; l < k; ++l) {
					if (l != j) {
						if (dp[i - 1][l] + 1 < dp[i][j]) {
							peche[i][j] = l;
							dp[i][j] = dp[i - 1][l] + 1;
						}
					} 
				}
			}
		}
	}
	int ans = INF, letter = 0;
	for (int i = 0; i < 26; ++i) {
		if (dp[n - 1][i] < ans) {
			letter = i;
			ans = dp[n - 1][i];
		}
	}
	for (int i = n - 1; i >= 0 && letter >= 0; --i) {
		res[i] = 'A' + letter;
		letter = peche[i][letter];
	}
	printf("%d\n", ans);
	puts(res);
	return 0;
}