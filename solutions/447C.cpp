// http://codeforces.com/contest/447/problem/C

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int valid[N];
int a[N], sz[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	valid[1] = 1;
	a[n + 1] = -1;
	int l = 1, r = 1;
	for (int i = 2; i <= n + 1; ++i) {
		if (a[i] > a[i - 1]) {
			valid[i] = valid[i - 1];
			++r;
		} else {
			valid[i] = valid[i - 1] + 1;
			sz[r] = r - l + 1;
			sz[l] = r - l + 1;
			l = r = i;
		}
	}
	for (int i = 1, curr = 1; i <= n; ++i) {
		if (sz[i] == 0) {
			sz[i] = curr;
		} else {
			curr = sz[i];
		}
	}
	// for (int i = 1; i <= n; ++i) {
	// 	cout << sz[i] << " ";
	// }
	int ans = *max_element(sz + 1, sz + n + 1);
	for (int i = n; i >= 1; --i) {
		if (i == n && a[i] <= a[i - 1]) {
			ans = max(ans, sz[i - 1] + 1);
		} else if (i == 1 && a[i] >= a[i + 1] && n > 1) {
			ans = max(ans, sz[i + 1] + 1);
		} else if (1 < i && i < n) {
			if (valid[i - 1] == valid[i + 1]) {
				continue;
			}
			if (valid[i - 1] != valid[i]) {
				ans = max(ans, sz[i - 1] + 1);
			} 
			if (valid[i + 1] != valid[i]) {
				ans = max(ans, sz[i + 1] + 1);
			}
			if (a[i + 1] - a[i - 1] > 1) {
				if (valid[i - 1] != valid[i] && valid[i] != valid[i + 1]) {
					ans = max(ans, sz[i - 1] + 1 + sz[i + 1]);
				} else {
					ans = max(ans, sz[i - 1] + sz[i + 1]);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}