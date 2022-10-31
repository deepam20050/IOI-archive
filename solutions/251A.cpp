// http://codeforces.com/problemset/problem/251/A
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N];

int main() {
	int n, d;
	scanf("%d %d", &n, &d);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		int idx = upper_bound(a + i + 1, a + n + 1, a[i] + d) - a;
		//cout << idx << '\n';
		while (idx >= n + 1 || a[idx] > a[i] + d) {
			--idx;
		}
		long long rem = idx - i - 1;
		if (rem < 0) {
			continue;
		}
		ans += (rem * (rem + 1)) / 2;
	}
	printf("%lld\n", ans);
	return 0;
}