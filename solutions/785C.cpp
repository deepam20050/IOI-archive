// http://codeforces.com/problemset/problem/785/C
// Still a bit confusion, Look forward in future 

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	ll n,m;
	scanf("%lld %lld",&n,&m);

	if (n <= m) {
		printf("%lld\n",n);
		return 0;
	}
	n -= m;
	ll l = 0, r = 2e9;

	while (l < r) {
		ll m = l + r >> 1;
		ll val = (m*(m+1))/2;
		if (val >= n)
			r = m;
		else l = m+1;
	}

	printf("%lld\n",l + m);

	return 0;
}