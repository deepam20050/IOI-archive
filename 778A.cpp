// http://codeforces.com/contest/778/problem/A
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

string t, p;

int n, m;

int a[N];
bool used[N];

bool F(int x) {
	for (int i = 0; i < n; ++i) {
		used[i] = 0;
	}
	for (int i = 0; i <= x; ++i) {
		used[a[i]] = 1;
	}
	int j = 0;
	for (int i = 0; i < n && j < m; ++i) {
		if (!used[i] && t[i] == p[j]) {
			++j;
		}
	}
	return j == m;
}

int main() {
	cin >> t >> p;
	n = t.size();
	m = p.size();
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		--a[i];
	}
	int l = 0, r = n - 1, ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (F(mid)) {
			ans = mid + 1;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}