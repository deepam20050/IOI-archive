// http://codeforces.com/problemset/problem/416/C

#include "bits/stdc++.h"

using namespace std;

const int N = 1010;

int c[N], p[N], ans[N];
pair <int, int> t[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", c + i, p + i);
	}
	int k;
	scanf("%d", &k);
	for (int i = 1; i <= k; ++i) {
		scanf("%d", &t[i].first);
		t[i].second = i;
	}
	sort(t + 1, t + k + 1);
	int cnt = 0, sum = 0;
	for (int i = 1; i <= k; ++i) {
		int idx = -1, mx = -1;
		for (int j = 1; j <= n; ++j) {
			if (c[j] != -1 && c[j] <= t[i].first) { 
				if (p[j] >= mx) {
					idx = j;
					mx = p[j];
				}
			}
		}
		if (mx != -1) {
			++cnt;
			sum += mx;
			ans[t[i].second] = idx;
			c[idx] = p[idx] = -1;
		}
	}
	printf("%d %d\n", cnt, sum);
	for (int i = 1; i <= k; ++i) {
		if (ans[i] != 0) {
			printf("%d %d\n", ans[i], i);
		}
	}
	return 0;
}