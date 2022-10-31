// http://codeforces.com/problemset/problem/285/C
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 3e5;

long ar[N];

long abso(long x) {
	return x < 0 ? -x : x;
}

int main() {
	int n;
	scanf("%d",&n);

	for (int i = 0; i < n; ++i) {
		scanf("%ld",ar + i);
	}

	long long ans = 0;
	sort(ar, ar + n);

	for (int i = 0, num = 1; i < n; ++i, ++num) {
		ans += abso(ar[i] - num);
	}

	printf("%lld\n",ans);

	return 0;
}