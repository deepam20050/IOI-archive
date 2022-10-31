// http://codeforces.com/contest/446/problem/A

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N];
int l[N];
int r[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	l[n] = 1;
	for (int i = n - 1; i >= 1; --i) {
		if (a[i] < a[i + 1]) {
			l[i] = 1 + l[i + 1];
		} else {
			l[i] = 1;
		}
	}
	r[1] = 1;
	for (int i = 2; i <= n; ++i) {
		if (a[i] > a[i - 1]) {
			r[i] = 1 + r[i - 1];
		} else {
			r[i] = 1;
		}
	}
	int ans = max(*max_element(l + 1, l + n + 1), *max_element(r + 1, r + n + 1));
	for (int i = 1; i <= n; ++i) {
		if (i + 1 <= n && a[i] >= a[i + 1] ) {
			ans = max(ans, 1 + l[i + 1]);
		} 
		if (i - 1 >= 1 && a[i] <= a[i - 1]) {
			ans = max(ans, 1 + r[i - 1]);
		}
		if (i + 1 <= n && i - 1 >= 1 && a[i + 1] - a[i - 1] > 1) {
			ans = max(ans, l[i + 1] + r[i - 1] + 1);
		}
	}
	printf("%d", ans);
	return 0;
}