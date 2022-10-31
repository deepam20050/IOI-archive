#include <bits/stdc++.h>

using namespace std;

const int N = 122, oo = 1 << 28;

int dp[N][N];
int d[N][N];
int p[N][N];

void get_path(int i, int j) {
  if (!p[i][j]) {
    printf("%d %d ", i, j);
    return;
  }
  get_path(i, p[i][j]);
  get_path(p[i][j], j);
}

int main() {
  int n, m;
  while (scanf("%d", &n) && n != -1 && scanf("%d", &m)) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[i][j] = oo;
        d[i][j] = oo;
      }
    }
    for (int i = 0; i < m; ++i) {
      int x, y, z;
      scanf("%d %d %d", &x, &y, &z);
      dp[x][y] = min(dp[x][y], z);
      dp[y][x] = min(dp[y][x], z);
      d[x][y] = min(d[x][y], z);
      d[y][x] = min(d[y][x], z);
    }
    for (int k = 1; k <= n; ++k) {
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          if (dp[i][k] + dp[k][j] < dp[i][j]) {
            dp[i][j] = dp[i][k] + dp[k][j];
            p[i][j] = k;
          }
        }
      }
    }
    int dist = oo;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (p[i][j] && d[j][i] != oo) {
          dist = min(dist, d[j][i] + dp[i][j]);
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (p[i][j] && d[j][i] != oo && d[j][i] + dp[i][j] == dist) {
          get_path(i, j);
          j = oo;
          i = oo;
        }
      }
    }
    cout << '\n';
    cout << dist << '\n';
    if (dist == oo) {
      puts("No Solution.");
    } else {
      printf("\n");
    }
  }
  return 0;
}