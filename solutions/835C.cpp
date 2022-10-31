// http://codeforces.com/contest/835/problem/C

#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int dp[11][N][N];

int compute(int t, int x, int y) {
	if (x < 0 || y < 0) {
		return 0;
	}
	return dp[t][x][y];
}

int main() {
	int n, q, c;
	scanf("%d %d %d", &n, &q, &c);
	for (int i = 0; i < n; ++i) {
		int x, y, s;
		scanf("%d %d %d", &x, &y, &s);
		++dp[s][x][y];
	}
	for (int i = 0; i <= c; ++i) {
		for (int x = 1; x < N; ++x) {
			for (int y = 1; y < N; ++y) {
				dp[i][x][y] += compute(i, x - 1, y) + compute(i, x, y - 1) - compute(i, x - 1, y - 1);
 			}
		}
	}
	while (q--) {
		int t, x1, y1, x2, y2;
		cin >> t >> x1 >> y1 >> x2 >> y2;
		int dx = x1 - x2;
		int dy = y2 - y1;
		int xi, yi, xii, yii;
		if (dx >= 0) {
			if (dy >= 0) {
				xi = x1;
				yi = y1;
				xii = x2;
				yii = y2;
			} else {
				xi = x1;
				xii = x2;
				yi = y2;
				yii = y1;
			}
		} else {
			if (dy >= 0) {
				xi = x2;
				xii = x1;
				yi = y1;
				yii = y2;
			} else {
				xi = x2;
				xii = x1;
				yi = y2;
				yii = y1;
			}
		}
		int ans = 0;
		for (int i = 0; i <= c; ++i) {
			int tt = (i + t) % (c + 1);
			int am = compute(i, xi, yii) - compute(i, xi, yi - 1) - compute(i, xii - 1, yii) + compute(i, xii - 1, yi - 1);
			ans += tt * am;
		}
		cout << ans << '\n';
	}
	return 0;
}