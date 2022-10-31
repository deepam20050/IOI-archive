// http://codeforces.com/problemset/problem/492/B
// AC

#include <bits/stdc++.h>

using namespace std;

long ar[1001];

int main() {
	int n;
	long l;
	scanf("%d %ld",&n,&l);

	for (int i = 0; i < n; ++i)
		scanf("%ld",&ar[i]);
	sort(ar,ar+n);

	long ans = 2*max(ar[0],l-ar[n-1]);

	for (int i = 1; i < n; ++i)
		ans = max(ans,ar[i] - ar[i-1]);

	printf("%.9f\n",ans/2.0);

	return 0;
}