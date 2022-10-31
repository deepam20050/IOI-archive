// http://codeforces.com/contest/758/problem/C

#include "bits/stdc++.h"

using namespace std;

const int N = 123;

long long a[N][N], c[N][N];

int main() {
	int n, m, x, y;
	long long k;
	scanf("%d %d %lld %d %d", &n, &m, &k, &x, &y);
	if (n == 1) {
		long long cycle = k / m;
		int rem = k % m;
		for (int i = 1; i <= m; ++i) {
			a[1][i] = cycle;
		}
		for (int i = 1; i <= m && rem; ++i, --rem) {
			++a[1][i];
		}
	} else {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				++c[i][j];
			}
		}
		for (int i = n - 1; i >= 2; --i) {
			for (int j = 1; j <= m; ++j) {
				++c[i][j];
			}
		}
		long long cycle = k / (n * m + (n - 2) * m);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				a[i][j] = cycle * c[i][j];
			}
		}
		int rem = k % (n * m + (n - 2) * m);
		for (int i = 1; i <= n && rem; ++i) {
			for (int j = 1; j <= m && rem; ++j) {
				++a[i][j];
				--rem;
			}
		}
		for (int i = n - 1; i >= 2 && rem; --i) {
			for (int j = 1; j <= m && rem; ++j) {
				++a[i][j];
				--rem;
			}
		}
	}
	long long o = -1, p = 2e18, q = a[x][y];
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			o = max(o, a[i][j]);
			p = min(p, a[i][j]);
		}
	}
	printf("%lld %lld %lld", o, p, q);
	return 0;
}