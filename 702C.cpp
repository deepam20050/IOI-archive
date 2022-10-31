// http://codeforces.com/problemset/problem/702/C

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N], b[N];


int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", b + i);
	}
	sort(a, a + n);
	sort(b, b + m);
	int mx = 0;
	for (int i = 0; i < n; ++i) {
		int idx1 = lower_bound(b, b + m, a[i]) - b, idx2 = lower_bound(b, b + m, a[i]) - b;
		if (idx1 < m && b[idx1] == a[i]) {
			mx = max(mx, 0);
			continue;
		}
		if (idx2 != m) {
			if (idx2 - 1 >= 0) {
				--idx2;
				mx = max(mx, min(a[i] - b[idx2], b[idx1] - a[i]));
			} else {
				mx = max(mx, b[idx1] - a[i]);
			}
			continue;
		}
		if (idx1 == m) {
			--idx1;
		}
		mx = max(mx, a[i] - b[idx1]);
	}
	printf("%d\n", mx);
	return 0;
}		