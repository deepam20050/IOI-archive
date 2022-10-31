// http://codeforces.com/problemset/problem/739/A

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, mini = 2e9;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		mini = min(mini, y - x + 1);
	}
	printf("%d\n", mini);
	for (int i = 0; i < n; ++i) {
		printf("%d ", i % mini);
	}
	return 0;
}