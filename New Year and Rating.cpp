// http://codeforces.com/problemset/problem/750/C
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5;
const long INF = 100000000;

int c[N], d[N];

int n;

int F(long x) {
	for (int i = 0; i < n; ++i) {
		if (x >= 1900 && d[i] != 1) {
			return 1;
		} 
		if (x < 1900 && d[i] != 2) {
			return 2;
		}
		x += c[i];
	}
	return 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", c + i, d + i);
	}
	long l = -INF, r = INF, ans = -INF;
	while (l <= r) {
		long m = (l + r) >> 1;
		int y = F(m);
		if (y == 0) {
			ans = m;
			l = m + 1;
		} else if (y == 1) {
			r = m - 1;
		} else {
			l = m + 1;
		}

	}
	if (ans == INF) {
		puts("Infinity");
	} else if (ans == -INF) {
		puts("Impossible");
	} else {
		printf("%ld", ans + accumulate(c, c + n, 0L));
	}
	return 0;
}