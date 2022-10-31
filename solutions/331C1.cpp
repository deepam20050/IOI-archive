// http://codeforces.com/contest/331/problem/C1
// This is the solution for ONLY subtask - 1 in which n <= 10^6
// This problem came in ABBYY CUP 3.0 FINALS (ONLINE ROUND)

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

unordered_map <ll, ll> dp;

ll solve (ll val) {
	if (val == 0) {
		return 0;
	} else if (dp[val] != 0) {
		return dp[val];
	}
	ll mini = 1e18 + 10, temp = val;
	while (temp > 0) {
		int dig = temp % 10LL;
		if (dig != 0) {
			mini = min(solve(val - dig), mini);
		}
		temp /= 10;
	}
	return dp[val] = mini + 1;
}

int main() {
	long long n;
	scanf("%lld", &n);
	printf("%lld", solve(n));
	return 0;
}