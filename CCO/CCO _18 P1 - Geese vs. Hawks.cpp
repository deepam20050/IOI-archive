#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int dp[N][N];
int a[N];
int b[N];
char s[N];
char t[N];
pair < int, char > one[N];
pair < int, char > two[N];
int n;

int f (int l, int r) {
	if (l < 1 || r < 1) {
		return 0;
	}
	if (dp[l][r] != -1) {
		return dp[l][r];
	}
	dp[l][r] = 0;
	// say we choose the xth game
	int p1 = one[l].first;
	char ch1 = one[l].second;
	for (int i = r; i >= 1; --i) {
		int p2 = two[i].first;
		char ch2 = two[i].second;
		if (p1 > p2  && ch1 > ch2) {
			dp[l][r] = max(dp[l][r], p1 + p2 + f(l - 1, i - 1));
		}
		if (p2 > p1 && ch2 > ch1) {
			dp[l][r] = max(dp[l][r], p1 + p2 + f(l - 1, i - 1));
		}
	}
	// we don't choose the lth person
	dp[l][r] = max(dp[l][r], f(l - 1, r));
	return dp[l][r];
}

int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	scanf("%s", t + 1);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", b + i);
	}
	for (int i = 1; i <= n; ++i) {
		one[i] = {a[i], s[i]};
		two[i] = {b[i], t[i]};
	}
	sort(one + 1, one + n + 1);
	sort(two + 1, two + n + 1);
	memset(dp, -1, sizeof dp);
	printf("%d\n", f(n, n));
	return 0;
}