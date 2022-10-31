// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/pablos-market-35a291a1/description/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int M = 1e6 + 1;

int cnt[M];
int arr[N];
int idx[M];
int dp[N][100];
int n;
int q;
int curr = 1;

inline void compute () {
	for (int i = 1; i < M; ++i) {
		for (int j = i; j < M; j += i) {
			++cnt[j];
		}
	}
}

int main() {
	scanf("%d", &n);
	compute();
	for (int i = 1; i <= n; ++i) {
		scanf("%d", arr + i);
		arr[i] = cnt[arr[i]];
		if (!idx[arr[i]]) {
			idx[arr[i]] = curr++;
		}
		arr[i] = idx[arr[i]];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < curr; ++j) {
			dp[i][j] = dp[i - 1][j];
		}
		++dp[i][arr[i]];
	}
	scanf("%d", &q);
	while (q--) {
		int l, r;
		scanf("%d %d", &l, &r);
		long long ans = 0;
		for (int i = 0; i < curr; ++i) {
			int val = dp[r][i] - dp[l - 1][i];
			ans += 1LL * val * (val - 1) >> 1LL;
		}
		printf("%lld\n", ans);
	}
	return 0;
}