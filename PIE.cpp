// http://www.spoj.com/problems/PIE/
// AC
// Do any searches like binary, terenary search on iterations approx ~ 300

#include <bits/stdc++.h>

using namespace std;

const long double pi = 3.14159265358979323846264338327950;
const long double eps = 1e-6;
const int N = 10010;

long double a[N];

int n, f;

bool F(long double x) {
	int total = 0;
	for (int i = 0; i < n; ++i) {
		total += (int)(a[i] / x);
	}
	return total >= f;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &f);
		++f;
		for (int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			a[i] = (double) (x * x * pi);
		}
		sort(a, a + n);
		long double l = 0, r = a[n - 1], ans = 0.0;
		for (int i = 1; i < 300; ++i) {
			long double mid = (l + r) / 2.0;
			if (F(mid)) {
				ans = mid;
				l = mid;
			} else {
				r = mid;
			}
		}
		printf("%.4Lf\n", ans);
	}
	return 0;
}