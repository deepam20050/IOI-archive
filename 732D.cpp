// http://codeforces.com/problemset/problem/732/D
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int days[N], t[N], each[N], last[N];

int n, m;

bool F(int d) {
	memset(each, 0, sizeof each);
	for (int i = 1; i <= m; ++i) {
		last[i] = -1;
	}
	for (int i = 1; i <= d; ++i) {
		last[days[i]] = max(last[days[i]], i);
	}
	for (int i = 1; i <= m; ++i) {
		if (last[i] == -1) {
			return 0;
		}
	}
	int ptr = 1;
	for (int i = 1; i <= d; ++i) {
		if (days[i] && i == last[days[i]]) {
			int req = t[days[i]];
			while (ptr < i && req) {
				if (each[ptr]) {
					++ptr;
				} else {
					each[ptr] = 1;
					--req;
					++ptr;
				}
			}
			if (req) {
				return 0;
			}
			each[i] = 1;
		}
	}
	return 1;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", days + i);
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d", t + i);
	}
	if (!F(n)) {
		return !printf("-1");
	}
	int l = 1, r = n, ans = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (F(mid)) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}