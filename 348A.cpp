// http://codeforces.com/problemset/problem/348/A
// AC

#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main() {
	int n;
	scanf("%d",&n);
	double sum = 0;
	ll mx = -1;
	for (int i = 0; i < n; ++i) {
		ll x;
		scanf("%lld",&x);
		sum += x;
		mx = max(mx,x);
	}

	ll ans = ceil((double)(sum/(n-1)));
	printf("%lld\n",max(ans,mx));
	return 0;
}