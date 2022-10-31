#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int dp[N][N];
char s[N];
char t[N];

int f (int i, int j) {
	if (min(i, j) == 0) {
		return max(i, j);
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	dp[i][j] = 1e9;
	if (i > 1 && j > 1 && s[i] == t[j - 1] && s[i - 1] == t[j]) {
		dp[i][j] = min(dp[i][j], f(i - 2, j - 2) + 1);
	}
	dp[i][j] = min(dp[i][j], f(i, j - 1) + 1);
	dp[i][j] = min(dp[i][j], f(i - 1, j - 1) + (s[i] != t[j]));
	dp[i][j] = min(dp[i][j], f(i - 1, j) + 1);
	return dp[i][j];
}

int main() {
	while (scanf("%s %s", s + 1, t + 1) && s[1] != '*') {
		memset(dp, -1, sizeof dp);
		int ans1 = f(strlen(s + 1), strlen(t + 1));
		printf("%d\n", ans1);
	}
	return 0;
}