// http://codeforces.com/problemset/problem/466/A
// AC

#include <bits/stdc++.h>

using namespace std;

int dp[1010];

int main() {
  int n, m, a, b;
  scanf("%d %d %d %d", &n, &m, &a, &b);
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    dp[i] = a + dp[i - 1];
    if (i - m >= 0) {
      dp[i] = min(dp[i], dp[i - m] + b);
    } else {
      dp[i] = min(dp[i], b);
    }
  }
  printf("%d\n", dp[n]);
  return 0;
}

