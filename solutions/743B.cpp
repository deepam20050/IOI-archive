// http://codeforces.com/problemset/problem/743/B
// AC

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll d[51];
ll a[51];

int main() {
	d[0] = 1;
	for (int i = 1; i <= 50; ++i) {
		d[i] = d[i-1] * 2;
	}
	a[1] = 1;
	ll sum = 1;
	for (int i = 2; i <= 50; ++i) {
		a[i] = d[i-1];
	}

	int n;
	ll k;
	scanf("%d %lld",&n,&k);

	for (int i = 1; i <= n; ++i) {
		if ((k-a[i])%d[i] == 0) {
			printf("%d\n",i);
			return 0;
		}
	}

	return 0;
}