// http://www.spoj.com/problems/TRIKA/

#include <bits/stdc++.h>

using namespace std;

const int N = 123;

int dp[N][N];
int a[N][N];

int n, m;

int solve (int x, int y) {
  if (x >= n || y >= m) {
    return 1 << 20;
  }
  if (dp[x][y] != -1) {
    return dp[x][y];
  }
  return dp[x][y] = min(solve(x + 1, y), solve(x, y + 1)) + a[x][y];
}

int main() {
  int x, y;
  scanf("%d %d %d %d", &n, &m, &x, &y);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", a[i] + j);
    }
  }
  memset(dp, -1, sizeof dp);
  dp[n - 1][m - 1] = a[n - 1][m - 1];
  int ans =  a[x - 1][y - 1] - (solve(x - 1, y - 1) - a[x - 1][y - 1]);
  if (ans < 0) {
    puts("N");
  } else {
    printf("Y %d\n", ans);
  }
  return 0;
}