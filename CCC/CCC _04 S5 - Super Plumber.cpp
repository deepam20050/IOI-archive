// https://dmoj.ca/problem/ccc04s5

#include <bits/stdc++.h>

using namespace std;

const int N = 123;

char s[N];
int g[N][N];
int dp[N][N];

int n, m;

inline void get() {
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    for (int j = 0; j < m; ++j) {
      dp[i][j] = -1;
      if (s[j] == '*') {
        g[i][j] = -1;
      } else if (s[j] == '.') {
        g[i][j] = 0;
      } else {
        g[i][j] = s[j] - '0';
      }
    }
  }
}

int main() {
  while (scanf("%d %d", &n, &m) && n != 0) {
    get();
    dp[n - 1][0] = g[n - 1][0];
    for (int i = n - 2; i >= 0; --i) {
      if (g[i][0] >= 0) {
        dp[i][0] = g[i][0] + dp[i + 1][0];
      } else {
        break;
      }
    }
    for (int j = 1; j < m; ++j) {
      for (int i = 0; i < n; ++i) {
        if (dp[i][j - 1] >= 0) {
          int sum = dp[i][j - 1];
          for (int k = i; k < n; ++k) {
            if (g[k][j] >= 0) {
              sum += g[k][j];
              dp[k][j] = max(dp[k][j], sum);
            } else {
              break;
            }
          }
        }
      }
      for (int i = n - 1; i >= 0; --i) {
        if (dp[i][j - 1] >= 0) {
          int sum = dp[i][j - 1];
          for (int k = i; k >= 0; --k) {
            if (g[k][j] >= 0) {
              sum += g[k][j];
              dp[k][j] = max(dp[k][j], sum);
            } else {
              break;
            }
          }
        } 
      }
    }
    printf("%d\n", dp[n - 1][m - 1]);
  }
  return 0;
}