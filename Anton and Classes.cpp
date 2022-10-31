// http://codeforces.com/problemset/problem/785/B
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5;

int main() {
	int n;
	scanf("%d", &n);
	long l = 1e10, r = 0, a = 1e10, b = 0;
	for (int i = 0; i < n; ++i) {
		long x, y;
		scanf("%ld %ld", &x, &y);
		l = min(y, l);
		b = max(b, x);
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		long x, y;
		scanf("%ld %ld", &x, &y);
		r = max(r, x);
		a = min(a, y);
	}
	long ans = max(r - l, b - a);
	if (ans < 0) ans = 0;
	printf("%ld\n", ans);
	return 0;
}