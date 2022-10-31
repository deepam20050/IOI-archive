// https://dmoj.ca/problem/ccc15j5
// AC

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll dp[251][251];

ll go(int n, int k) {
	if (n < k) 
		return 0;
	if (k == 1 || k == n)
		return 1;
	if (dp[n][k] != -1) 
		return dp[n][k];
	return dp[n][k] = go(n - 1, k - 1) + go(n - k, k);
}

int main() {
	memset(dp, -1, sizeof dp);
	int n, k;
	scanf("%d %d",&n, &k);
	printf("%lld\n", go(n, k));

	return 0;
}