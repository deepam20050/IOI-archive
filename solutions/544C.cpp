#include <bits/stdc++.h>

using namespace std;

const int N = 510;

int dp[N][N];

int main() {
  int n, m, b, mod;
  scanf("%d %d %d %d", &n, &m, &b, &mod);
  dp[0][0] = 1;
  for (int i = 0, x; i < n; ++i) {
    scanf("%d", &x);
    for (int j = 1; j <= m; ++j) {
      for (int k = x; k <= b; ++k) {
        dp[j][k] += dp[j - 1][]
      }
    }
  }
  printf("%d", dp[m][b]);
  return 0;
}