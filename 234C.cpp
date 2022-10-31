// http://codeforces.com/problemset/problem/234/C

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N], pos[N], neg[N];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	int ans = n;
	pos[0] = a[0] >= 0 ? 1 : 0;
	for (int i = 1; i < n; ++i) {
		pos[i] = pos[i - 1] + (a[i] >= 0 ? 1 : 0);
	}
	neg[n - 1] = a[n - 1] <= 0 ? 1 : 0;
	for (int i = n - 2; i >= 0; --i) {
		neg[i] = neg[i + 1] + (a[i] <= 0 ? 1 : 0);
	}
	for (int i = 0; i < n - 1; ++i) {
		ans = min(ans, pos[i] + neg[i + 1]);
	}
	printf("%d", ans);
	return 0;
}