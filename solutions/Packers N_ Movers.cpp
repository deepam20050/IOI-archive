// https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/packers-n-movers/

#include <bits/stdc++.h>

using namespace std;

const int N = 300, oo = 2e9;

int a[N], dp[N][N];

int m, n;

int solve (int idx, int guy) {
  if (guy < 0) {
    return oo;
  }
  if (dp[idx][guy] != -1) {
    return dp[idx][guy];
  }
  dp[idx][guy] = oo;
  for (int i = 0, sum = 0; i < n && idx + i < n; ++i) {
    sum += a[idx + i];
    dp[idx][guy] = min(dp[idx][guy], max(sum, solve(idx + i + 1, guy - 1)));
  }
  return dp[idx][guy];
}

int main() {
  memset(dp, -1, sizeof dp);
  scanf("%d %d", &m, &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 0; i <= m; ++i) {
    dp[n][i] = 0;
  }
  printf("%d\n", solve(0, m));
  return 0;
}