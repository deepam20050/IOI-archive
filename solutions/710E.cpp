// http://codeforces.com/problemset/problem/710/E
// AC

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e7+1;

ll dp[N];

int main() {
	int n; 
	ll x,y;
	scanf("%d %lld %lld",&n,&x,&y);

	for (int i = 1; i <= n; ++i) {
		dp[i] = dp[i-1] + x;
		if (i&1)
			dp[i] = min(dp[i], dp[(i+1)/2] + x + y);
		else 
			dp[i] = min(dp[i], dp[i/2] + y);
	}

	printf("%lld\n",dp[n]);

	return 0;
}