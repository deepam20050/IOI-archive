// https://dmoj.ca/problem/ccc15s5
// Very nice DP problem :)

#include <bits/stdc++.h>

using namespace std;

const int N = 3e3 + 5;
const int M = 1e2 + 5;

int dp[N][2][M][M];
int arr[N];
int brr[M];
int n;
int m;

int solve (int pos, int take, int l, int r) {
	int &ret = dp[pos][take][l][r];
	if (ret != -1) {
		return ret;
	}
	if (pos == n + 1) {
		if (l <= r) {
			if (take) {
				return ret = brr[r] + solve(pos, 0, l, r - 1);
			} else {
				return ret = solve(pos, 1, l + 1, r);
			}
		}
		return ret = 0;
	}
	if (take) {
		ret = max(solve(pos, 0, l, r), arr[pos] + solve(pos + 1, 0, l, r));
		if (l <= r) {
			ret = max(ret, brr[r] + solve(pos, 0, l, r - 1));
		}
	} else {
		ret = solve(pos + 1, 1, l, r);
		if (l <= r) {
			ret = max(ret, solve(pos, 1, l + 1, r));
		}
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", arr + i);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d", brr + i);
	}
	sort(brr + 1, brr + m + 1);
	memset(dp, -1, sizeof dp);
	printf("%d\n", solve(1, 1, 1, m));
	return 0;
}