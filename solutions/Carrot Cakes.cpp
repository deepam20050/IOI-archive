// http://codeforces.com/contest/799/problem/A
// AC

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, t, k, d;
	scanf("%d %d %d %d", &n, &t, &k, &d);
	int c1 = 0, c2 = 0, a = 0, b = 0;
	for (int i = 1; i <= 100000000; ++i) {
		if (i % t == 0) {
			a += k;
		}
		if (a >= n) {
			c1 = i;
			break;
		}
	}
	for (int i = 1; i <= 100000000; ++i) {
		if (i % t == 0) {
			b += k;
		}
		if (i > d && (i - d) % t == 0) {
			b += k;
		}
		if (b >= n) {
			c2 = i;
			break;
		}
	}
	if (c1 <= c2) {
		puts("NO");
	} else {
		puts("YES");
	}
	return 0;
}