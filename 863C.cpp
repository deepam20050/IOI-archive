// http://codeforces.com/contest/863/problem/C

#include "bits/stdc++.h"

using namespace std;

const int N = 5;

int alice[N][N], bob[N][N];
bool used[N][N];

void calc(int a, int b, long long &x, long long &y) {
	if (a == 3 && b == 2) {
		++x;
	} else if (a == 2 && b == 3) {
		++y;
	} else if (a == 2 && b == 1) {
		++x;
	} else if (a == 1 && b == 2) {
		++y;
	} else if (a == 1 && b == 3) {
		++x;
	} else if (a == 3 && b == 1) {
		++y;
	}
}

void d(int val) {
	printf("%d\n", val);
}

int main() {
	long long k;
	int a, b;
	scanf("%lld %d %d", &k, &a, &b);
	for (int i = 1; i <= 3; ++i) {
		for (int j = 1; j <= 3; ++j) {
			scanf("%d", &alice[i][j]);
		}
	}
	for (int i = 1; i <= 3; ++i) {
		for (int j = 1; j <= 3; ++j) {
			scanf("%d", &bob[i][j]);
		}
	}
	long long x0 = 0, y0 = 0;
	int len = 0;
	while (!used[a][b] && len < k) {
		// printf("%d %d\n", a, b);
		++len;
		used[a][b] = 1;
		calc(a, b, x0, y0);
		int t1 = a, t2 = b;
		a = alice[t1][t2];
		b = bob[t1][t2];
		// printf("%d %d\n", a, b);
	}
	if (len == k) {
		return !printf("%lld %lld\n", x0, y0);
	}
	memset(used, 0, sizeof used);
	long long x1 = 0, y1 = 0;
	int len1 = 0;
	while (!used[a][b]) {
		++len1;
		used[a][b] = 1;
		calc(a, b, x1, y1);
		int t1 = a, t2 = b;
		a = alice[t1][t2];
		b = bob[t1][t2];
	}
	long long p1 = x0 - x1 + (k - (len - len1)) / len1 * x1;
	long long p2 = y0 - y1 + (k - (len - len1)) / len1 * y1;
	int len2 = (k - (len - len1)) % len1;
	while (len2) {
		--len2;
		calc(a, b, p1, p2);
		int t1 = a, t2 = b;
		a = alice[t1][t2];
		b = bob[t1][t2];
	}
	printf("%lld %lld", p1, p2);
	return 0;
}