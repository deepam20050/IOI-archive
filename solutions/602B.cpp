// http://codeforces.com/problemset/problem/602/B

#include "bits/stdc++.h"

using namespace std;

const int N = 100010;

int idx[N];

int main() {
	int n;
	scanf("%d", &n);
	int ans = 2;
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		++x;
		int id = min(idx[x - 1], min(idx[x + 1], idx[x]));
		id = max(id, max(idx[x - 2], idx[x + 2]));
		ans = max(ans, i - id);
		idx[x] = i;
	}
	printf("%d", ans);
	return 0;
}