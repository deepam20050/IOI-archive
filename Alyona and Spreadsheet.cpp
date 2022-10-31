// http://codeforces.com/problemset/problem/777/C
// AC

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	scanf("%d %d",&n, &m);

	long ar[n + 2][m + 2];
	long mx[n + 2];
	long nx[n + 2][m + 2];

	memset(ar, 0, sizeof ar);
	memset(mx, 0, sizeof mx);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%ld",&ar[i][j]);
		}
	}

	for (int i = n; i >= 1; i--) {
		for (int j = m; j >= 1; j--) {
			if (ar[i + 1][j] >= ar[i][j])
				nx[i][j] = nx[i + 1][j];
			else 
				nx[i][j] = i;
			mx[i] = max(mx[i], nx[i][j]);
		}
	}

	int q;
	scanf("%d", &q);

	while (q--) {
		int l, r;
		scanf("%d %d",&l, &r);
		mx[l] >= r ? puts("Yes") : puts("No");
	}

	return 0;
}