// http://codeforces.com/problemset/problem/816/C
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int g[N][N], row[N], col[N];

int sum = 1e9, who, n, m;

void solve (int x) {
	for (int i = 1; i <= m; ++i) {
		col[i] = g[1][i] - x;
		if (col[i] < 0) {
			return;
		}
	}
	for (int i = 2; i <= n; ++i) {
		row[i] = g[i][1] - col[1];
		if (row[i] < 0) {
			return;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (row[i] + col[j] != g[i][j]) {
				return;
			}
		}
	}
	int total = accumulate(row + 1, row + n + 1, 0) + accumulate(col + 1, col + m + 1, 0);
	if (total < sum) {
		sum = total;
		who = x;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &g[i][j]);
		}
	}
	who = -1;
	for (int i = 0; i <= 500; ++i) {
		memset(row, 0, sizeof row);
		memset(col, 0, sizeof col);
		row[1] = i;
		solve(i);
	}
	if (who == -1) {
		return !printf("-1");
	}
	memset(row, 0, sizeof row);
	memset(col, 0, sizeof col);
	row[1] = who;
	solve(who);
	printf("%d\n", sum);
	for (int i = 1; i <= n; ++i) {
		while (row[i]--) {
			printf("row %d\n", i);
		}
	}
	for (int i = 1; i <= m; ++i) {
		while (col[i]--) {
			printf("col %d\n", i);
		}
	}
	return 0;
}