// http://www.spoj.com/problems/UPDATEIT/
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(a, 0, sizeof a);
		int n, u;
		scanf("%d %d", &n, &u);
		while (u--) {
			int x, y, v;
			scanf("%d %d %d", &x, &y, &v);
			a[x] += v;
			a[y + 1] -= v;
		}
		for (int i = 1; i < n; ++i) {
			a[i] += a[i - 1];
		}
		int q;
		scanf("%d", &q);
		while (q--) {
			int x;
			scanf("%d", &x);
			printf("%d\n", a[x]);
		}
	}
	return 0;
}