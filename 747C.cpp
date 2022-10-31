// http://codeforces.com/contest/747/problem/C

#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int a[N];

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	for (int i = 1, t, k, d; i <= q; ++i) {
		scanf("%d %d %d", &t, &k, &d);
		for (int j = 1; j <= n; ++j) {
			if (a[j] < t) {
				a[j] = 0;
			}
		}
		int cnt = 0;
		for (int j = 1; j <= n && cnt < k; ++j) {
			if (!a[j]) {
				++cnt;
			}
		}
		if (cnt < k) {
			puts("-1");
		} else {
			int sum = 0;
			for (int j = 1, cc = 0; j <= n && cc < k; ++j) {
				if (!a[j]) {
					a[j] = t + d - 1;
					sum += j;
					++cc;
				}
			}
			printf("%d\n", sum);
		}
	}
	return 0;
}