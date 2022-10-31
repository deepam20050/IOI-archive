// https://www.spoj.com/problems/DSUBSEQ/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

char str[N];
int dp[N];
int lst[26];

int tc;

inline void mod (int &x) {
	if (x >= MOD) {
		x -= MOD;
	}
	x += MOD;
	if (x >= MOD) {
		x -= MOD;
	}
}

int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%s", str + 1);
		int n = strlen(str + 1);
		memset(lst, 0, sizeof lst);
		dp[0] = 1;
		for (int i = 1; i <= n; ++i) {
			dp[i] = dp[i - 1] << 1;
			mod(dp[i]);
			if (lst[str[i] - 'A']) {
				dp[i] -= dp[lst[str[i] - 'A'] - 1];
			}
			mod(dp[i]);
			lst[str[i] - 'A'] = i;
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}