// http://codeforces.com/problemset/problem/776/C
// AC

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 10;

int ar[N];

ll abso(ll x) {
	return x < 0 ? -x : x;
}

int main() {
	int n, k;
	ll sum = 0;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; ++i) {
		scanf("%d", ar + i);
		sum += abso(ar[i]);
	}

	ll x = 1, ans = 0;
	map <ll, int> mp;
	while (x <= sum) {
		mp.clear();
		++mp[0];
		ll s = 0;
		for (int i = 0; i < n; ++i) {
			s += ar[i];
			ans += mp[s - x];
			++mp[s];
		}
		x *= k;
		if (x == 1 && abso(k) == 1) {
			break;
		}
	}

	printf("%lld",ans);

	return 0;
}