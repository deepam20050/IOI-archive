// http://codeforces.com/problemset/problem/734/C

#include "bits/stdc++.h"

using namespace std;
using ll = unsigned long long;

const int N = 200010;

int best[N];
int s1[N];
int c1[N];
int instant[N];
int c2[N];

int main() {
	ll n, m, k, x, s;
	scanf("%llu %llu %llu %llu %llu", &n, &m, &k, &x, &s);
	for (int i = 1; i <= m; ++i) {
		scanf("%d", s1 + i);
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d", c1 + i);
	}
	for (int i = 1; i <= k; ++i) {
		scanf("%d", instant + i);
	}
	for (int i = 1; i <= k; ++i) {
		scanf("%d", c2 + i);
	}
	best[1] = 1;
	for (int i = 2; i <= k; ++i) {
		if (instant[i] > instant[best[i - 1]]) {
			best[i] = i;
		} else {
			best[i] = best[i - 1];
		}
	}
	ll ans = n * x; // case1 : use no magic
	for (int i = 1; i <= k; ++i) {
		if (c2[i] <= s) {
			ans = min(ans, (n - instant[i]) * x); // case2 : use ONLY type 2 magic
		}
	}
	for (int i = 1; i <= m; ++i) {
		if (c1[i] <= s) {
			ans = min(ans, s1[i] * n); // case3 : use ONLY type 1 magic
		}
	}
	// case4 : use both type 1 and type 2 magic
	for (int i = 1; i <= m; ++i) {
		if (c1[i] <= s) {
			int idx = upper_bound(c2 + 1, c2 + k + 1, s - c1[i]) - c2;
			while (idx == k + 1 || c1[i] + c2[idx] > s) {
				--idx;
			}
			if (idx < 1) {
				continue;
			}
			ans = min(ans, (n - instant[best[idx]]) * s1[i]);
		}
	}
	printf("%llu\n", ans);
	return 0;
}