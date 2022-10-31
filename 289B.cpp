// http://codeforces.com/problemset/problem/289/B
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;

int ar[N];

int abs(int x) {
	return x < 0 ? -x : x;
}

int main() {
	int n,m,d;
	scanf("%d %d %d",&n,&m,&d);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) 
			scanf("%d",&ar[i * m + j]);
	}

	int mod = ar[0] % d;
	for (int i = 1; i < n * m; ++i) {
		if (ar[i] % d != mod) {
			puts("-1");
			return 0;
		}
	}

	sort(ar,ar + n * m,greater<int>());

	int mid = ar[(n * m)/2], ans = 0;

	for (int i = 0; i < n * m; ++i) {
		ans += abs (mid - ar[i]) / d;
	}

	printf("%d\n",ans);

	return 0;
}