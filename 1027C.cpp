#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

int cnt[N];
int v[(int)1e6 + 5];
int n;

inline long long sqr (long long x) {
	return 1LL * x * x;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		memset(cnt, 0, sizeof cnt);
		for (int i = 0, x; i < n; ++i) {
			scanf("%d", &x);
			++cnt[x];
		}
		int m = 0;
		for (int i = 1; i < N; ++i) {
			if (cnt[i] >= 2) {
				v[m++] = i;
			}
		}
		long long x = 1e4 + 1e3, y = 1e5 + 2;
		for (int i = 0; i < m; ++i) {
			long long val1 = 1e5, val2 = 1e5;
			if (i - 1 >= 0) {
				val1 = v[i - 1];
			}
			if (i + 1 < m) {
				val2 = v[i + 1];
			}
			long long a = v[i];
			long long b = 0;
			if (abs(val2 - a) >= abs(a - val1)) {
				b = val1;
			} else {
				b = val2;
			}
			if (x * y * (sqr(a) + sqr(b)) < a * b * (sqr(x) + sqr(y))) {
				x = a;
				y = b;
			}
			if (cnt[v[i]] >= 4) {
				x = v[i];
				y = v[i];
				break;
			}
		}
		printf("%lld %lld %lld %lld\n", x, x, y, y);
	}
	return 0;
}