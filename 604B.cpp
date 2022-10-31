// http://codeforces.com/problemset/problem/604/B
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+1;

int ar[N];

int main() {

	int n,k,ans = -1;
	scanf("%d %d",&n,&k);

	for (int i = 0; i < n; ++i) {
		scanf("%d",&ar[i]);
		ans = max(ans, ar[i]);
	}

	for (int i = 0; i < n - k; ++i) {
		ans = max(ans, ar[i] + ar[2 * (n - k) - 1 - i]);
	}

	printf("%d\n",ans);

	return 0;
}