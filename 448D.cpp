// http://codeforces.com/problemset/problem/448/D

#include <bits/stdc++.h>

using namespace std;

long long n, m, k;

bool F(long long x) {
	long long cnt = 0;
	for (int i = 1; i <= n; ++i) {
		cnt += min(m, x / i);
	}
	return cnt >= k;
}

int main() {
	scanf("%lld %lld %lld", &n, &m, &k);
	long long l = 1, r = n * m, ans = 0;
	while (l <= r) {
		long long mid = (l + r) >> 1;
		if (F(mid)) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	printf("%lld\n", l);
	return 0;
}