// http://codeforces.com/problemset/problem/861/A

#include "bits/stdc++.h"

using namespace std;

long long lcm(long long x, long long y) {
	return (x * y) / __gcd(x, y);
}

int main() {
	long long n;
	int k;
	scanf("%lld %d", &n, &k);
	long long val = 1;
	while (k--) {
		val *= 10;
	}
	printf("%lld", lcm(n, val));
	return 0;
}