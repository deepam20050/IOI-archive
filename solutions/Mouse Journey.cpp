// https://dmoj.ca/problem/ccc12s5
// AC

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 26;

ll dp[N][N];
bool g[N][N];

int main() {
	int r, c, k;
	scanf("%d %d %d",&r, &c, &k);

	while (k--) {
		int x, y;
		scanf("%d %d",&x, &y);
		g[x][y] = 1;
	}

	dp[r][c] = 1;

	for (int i = r; i >= 1; --i) {
		for (int j = c; j >= 1; --j) {
			if (g[i][j] || (i == r && j == c)) continue;
			if (j + 1 <= c) 
				dp[i][j] += dp[i][j + 1];
			if (i + 1 <= r)
				dp[i][j] += dp[i + 1][j];
		}
	}

	printf("%lld\n",dp[1][1]);

	return 0;
}