// https://dmoj.ca/problem/ccoprep16c2q2

#include <bits/stdc++.h>

using namespace std;

const int LN = 31;

int dp[LN];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1, x; i <= n; ++i) {
		scanf("%d", &x);
		int curr_mx = 0;
		for (int j = 0; j < LN; ++j) {
			bool set = x & (1 << j);
			if (set) {
				curr_mx = max(curr_mx, dp[j] + 1);
			}
		}
		for (int j = 0; j < LN; ++j) {
			if (x & (1 << j)) {
				dp[j] = max(dp[j], curr_mx);
			}
		}
	}
	printf("%d\n", *max_element(dp, dp + LN));
	return 0;
}