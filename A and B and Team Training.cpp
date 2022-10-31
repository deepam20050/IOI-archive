// http://codeforces.com/problemset/problem/519/C
// AC

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int ans = 0;
	for (int i = 0; i <= n; ++i) {
		int tp = i;
		int ln = n - i, lm = m - 2 * i;
		if (lm >= 0) {
			tp += min(lm, ln/2);
			ans = max(ans, tp);
		}
	}
	printf("%d\n", ans);
	return 0;
}