// http://codeforces.com/contest/689/problem/C

#include <bits/stdc++.h>

using namespace std;

long long m;

long long F(long long &n) {
	long long res = 0;
	for (long long k = 2; k <= 100000; ++k) {
		long long val = n / (k * k * k);
		long long root = val;
		res += root;
	}
	return res;
}

int main() {
	scanf("%lld", &m);
	long long l = 2, r = 1e18, ans = -1;
	for (int i = 0; i < 100; ++i) {
		long long n = (l + r) >> 1LL;
		long long temp = F(n);
		if (temp == m) {
			ans = n;
			r = n;
		} else if (temp > m) {
			r = n;
		} else {
			l = n;
		}
	}
	printf("%lld", ans);
	return 0;
}