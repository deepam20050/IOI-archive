// http://codeforces.com/problemset/problem/863/D

#include "bits/stdc++.h"

using namespace std;

const int N = 200010;

int a[N];
int t[N];
int l[N];
int r[N];

int n, q, m;

int solve (int idx) {
	for (int i = q; i >= 1; --i) {
		if (idx < l[i] || idx > r[i]) {
			continue;
		}
		if (t[i] == 1) {
			if (idx == l[i]) {
				idx = r[i];
			} else {
				--idx;
			}
		} else {
			idx = l[i] + r[i] - idx;
		}
	}
	return a[idx];
}

int main() {
	scanf("%d %d %d", &n, &q, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	for (int i = 1; i <= q; ++i) {
		scanf("%d %d %d", t + i, l + i, r + i);
	}
	while (m--) {
		int idx;
		scanf("%d", &idx);
		printf("%d ", solve(idx));
	}
	return 0;
}