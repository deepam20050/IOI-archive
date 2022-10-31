#include <bits/stdc++.h>

using namespace std;

int main() {
	scanf("%d %d %d", &n, &cs, &cf);
	if (n == 2) {
		return !printf("1");
	}
	for (int i = 1; i <= n; ++i) {
		dp[n - 2][i][0] = 1;
		dp[n - 2][i][1] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		pref[i][0] = pref[i - 1][0] + 1;
		pref[i][1] = pref[i - 1][1] + 1;
	}
	for (int i = n; i >= 1; --i) {
		suff[i][0] = suff[i + 1][0] + 1;
		suff[i][1] = suff[i + 1][0] + 1;
	}
	for (int i = 1; i <= n; ++i) {
		dp[n - 3][i][0] = pref[i - 1][1];
		dp[n - 3][i][1] = suff[i + 1][0];
		tmp_pref[i][0] = tmp_pref[i - 1][0] + dp[n - 3][i][0];
		tmp_pref[i][1] = tmp_pref[i - 1][1] + dp[n - 3][i][1];
		mod(tmp_pref[i][0]);
		mod(tmp_pref[i][1]);
	}
	for (int i = n; i >= 1; --i) {
		tmp_suff[i][0] = tmp_suff[i + 1][0] + dp[n - 3][i][0];
		tmp_suff[i][1] = tmp_suff[i + 1][1] + dp[n - 3][i][1];
		mod(tmp_suff[i][0]);
		mod(tmp_suff[i][1]);
	}
	for (int i = 1; i <= n; ++i) {
		pref[i][0] = tmp_pref[i][0];
		pref[i][1] = tmp_pref[i][1];
		suff[i][0] = tmp_suff[i][0];
		suff[i][1] = tmp_suff[i][1];
	}
	for (int j = n - 4; j > 1; --j) {
		memset(tmp_pref, 0, sizeof tmp_pref);
		memset(tmp_suff, 0, sizeof tmp_suff);
		for (int i = 2; i <= n; ++i) {
			dp[j][i][0] = pref[j + 1][i - 1][1] - 1LL * (i - 1) * dp[j + 2][i][0];
			mod(dp[j][i][0]);
			tmp_pref[i][0] = tmp_pref[i - 1][0] + dp[j][i][0];
			mod(tmp_pref[i][0]);
			
		}
	}
	return 0;
}