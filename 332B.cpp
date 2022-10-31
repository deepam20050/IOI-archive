// http://codeforces.com/problemset/problem/332/B

#include "bits/stdc++.h"

using namespace std;

const int N = 200010;

int a[N];
long long pref[N];
long long best[N];
int dp[N];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	pref[0] = a[0];
	for (int i = 1; i < n; ++i) {
		pref[i] = pref[i - 1] + a[i];
	}
	best[0] = pref[k - 1];
	for (int i = 1; i + k - 1 < n; ++i) {
		best[i] = pref[i + k - 1] - pref[i - 1];
	}
	int x = n - k;
	dp[x] = x;
	for (int i = n - k - 1; i >= 0; --i) {
		if (best[x] <= best[i]) {
			x = i;
		}
		dp[i] = x;
	}
	long long mx = -1;
	int idx1 = -1, idx2 = -1;
	for (int i = 0; i + k + k - 1 < n; ++i) {
		if (best[i] + best[dp[i + k]] > mx) {
			idx1 = i;
			idx2 = dp[i + k];
			mx = best[i] + best[dp[i + k]];
		}
	}
	printf("%d %d", idx1 + 1, idx2 + 1);
	return 0;
}