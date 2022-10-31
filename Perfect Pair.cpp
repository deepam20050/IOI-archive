// http://codeforces.com/problemset/problem/317/A
// AC

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	ll x, y, m;
	cin >> x >> y >> m;
	ll a = max(x, y), b = min(x, y);
	if (a >= m) {
		return !printf("0");
	} else if (a <= 0) {
		return !printf("-1");
	}
	ll ans = 0;
	if (b < 0) {
		ans = -b/a;
		b += a * ans;
	}
	while (a < m) {
		b += a;
		if (a < b) {
			swap(a, b);
		}
		++ans;
	}
	printf("%lld\n", ans);
	return 0;
}