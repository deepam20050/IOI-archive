// https://arc058.contest.atcoder.jp/tasks/arc058_b

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long MOD = 1e9 + 7;

long long fact[N];

long long power (long long x, long long y) {
	long long res = 1;
	while (y > 0) {
		if (y & 1LL) {
			res = 1LL * (res * x) % MOD;
		}
		y >>= 1LL;
		x = 1LL * (x * x) % MOD;
	}
	return res;
}

long long di (long long x, long long y) {
	return x * power(y, MOD - 2) % MOD;
}

long long calc (int x0, int y0, int x, int y) {
	int sum = x + y - x0 - y0;
	long long div1 = di(fact[sum], fact[x - x0]);
	div1 = di(div1, fact[y - y0]);
	return div1;
}

int main() {
	int h, w, a, b;
	scanf("%d %d %d %d", &h, &w, &a, &b);
	fact[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = fact[i - 1] * 1LL * i % MOD;
	}
	long long ret = 0;
	for (int i = 1; i <= h - a; ++i) {
		long long ans1 = calc(1, 1, i, b);
		long long ans2 = calc(i, b + 1, h, w);
		ret += 1LL * ans1 * ans2 % MOD;
		ret %= MOD;
	}
	printf("%lld\n", ret);
	return 0;
}