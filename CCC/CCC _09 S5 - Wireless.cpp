// https://dmoj.ca/problem/ccc09s5

#include <bits/stdc++.h>

using namespace std;

const int N = 3e4 + 5;
const int M = 1e3 + 5;

int add[N][M];

int main() {
	int n, m, k;
	scanf("%d %d %d", &m, &n, &k);
	while (k--) {
		int x, y, r, rate;
		scanf("%d %d %d %d", &y, &x, &r, &rate);
		int up = max(1, x - r);
		int down = min(m, x + r);
		for (int i = up; i <= down; ++i) {
			int leg = abs(i - x);
			int dist = sqrt(r * r - leg * leg);
			add[i][max(1, y - dist)] += rate;
			add[i][min(n, y + dist) + 1] -= rate;
		}
	}
	int mx = 0, cnt = 0;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			add[i][j] += add[i][j - 1];
			if (add[i][j] == mx) {
				++cnt;
			} else if (add[i][j] > mx) {
				mx = add[i][j];
				cnt = 1;
			}
		}
	}
	printf("%d\n%d", mx, cnt);
	return 0;
}