// https://www.codechef.com/AUG17/problems/CHEFFA

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2000, M = 300;
const ll mod = 1e9 + 7;

int a[N];
ll dp[N][M][M];

ll solve(int ai0, int ai1, int idx) {
	if (ai1 < 0) {
		return 0LL;
	}
	if (ai1 == 0 && a[idx + 2] == 0) {
		return dp[idx][ai0][ai1] = 1LL;
	}
	if (dp[idx][ai0][ai1] != -1LL) {
		return dp[idx][ai0][ai1];
	}
	dp[idx][ai0][ai1] = solve(ai1, a[idx + 2], idx + 1) % mod;
	for (int i = 1; i <= min(ai0, ai1); ++i) {
		dp[idx][ai0][ai1] = (dp[idx][ai0][ai1] + solve(ai1 - i, a[idx + 2] + i, idx + 1)) % mod;
	}
	return dp[idx][ai0][ai1];
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		memset(a, 0, sizeof a);
		memset(dp, -1LL, sizeof dp);
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
		}
		printf("%lld\n", solve(a[0], a[1], 0));
	}
	return 0;
}