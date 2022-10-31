// http://codeforces.com/contest/760/problem/B

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m, k;

ll sum(ll x) {
	return (x * (x + 1)) / 2;
}

ll total(ll y, ll x) {
	ll res = 0;
	if (y <= x) {
		res += sum(x) - sum(x - y);
	} else {
		res += sum(x) + y - x;
	}
	return res;
}

bool F(ll x) {
	return x + total(k - 1, x - 1) + total(n - k, x - 1) <= m;
}

int main() {
	scanf("%lld %lld %lld", &n, &m, &k);
	ll l = 1, r = m, ans = 0;
	while (l < r) {
		ll mid = (l + r) >> 1;
		if (F(mid + 1)) {
			ans = mid + 1;
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	printf("%lld", l);
	return 0;
}