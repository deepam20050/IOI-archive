// http://wcipeg.com/problem/noi97p4

#include <bits/stdc++.h>

using namespace std;

const int M = 101;

int mx[M];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < M; ++i) {
		mx[i] = -10010;
	}
	if (m - 1 <= 0) {
		puts("0");
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < m; ++j) {
			int x;
			scanf("%d", &x);
			mx[j] = max(mx[j], x);
		}
	}
	int ans = -10010, curr = mx[1];
	for (int i = 2; i < m; ++i) {
		curr = max(curr + mx[i], mx[i]);
		ans = max(curr, ans);
	}
	printf("%d", ans);
	return 0;
}