// http://codeforces.com/contest/448/problem/C

#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

int a[N];

int solve (int l, int r, int h) {
	if (l > r) {
		return 0;
	}
	int mini = 1e9 + 1;
	for (int i = l; i <= r; ++i) {
		mini = min(mini, a[i]);
	}
	int last = l, res = 0;
	for (int i = l; i <= r; ++i) {
		if (a[i] == mini) {
			res += solve(last, i - 1, mini);
			last = i + 1;
		}
	}
	res += solve(last, r, mini) + mini - h;
	return min(res, r - l + 1);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	printf("%d", solve(1, n , 0));
	return 0;
}