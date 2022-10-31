// http://codeforces.com/contest/798/problem/C
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N];

int main() {
	int n;
	scanf("%d", &n);
	int g = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		g = __gcd(g, a[i]);
	}
	if (g > 1) {
		return !printf("YES\n0\n");
	}
	int ans = 0;
	for (int i = 1; i < n; ++i) {
		int x = a[i], y = a[i + 1];
		if (x & 1) {
			a[i] = x - y;
			a[i + 1] = x + y;
			++ans;
			--i;
		}
	}
	while (a[n] & 1) {
		int x = a[n - 1], y = a[n];
		a[n - 1] = x - y;
		a[n] = x + y;
		++ans;
	}
	printf("YES\n%d\n",ans);

	return 0;
}