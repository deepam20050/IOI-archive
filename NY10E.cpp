// http://www.spoj.com/problems/NY10E/

#include <bits/stdc++.h>

using namespace std;

long long dp[123][10];

long long go(int idx, int val) {
  if (dp[idx][val] != -1) {
    return dp[idx][val];
  }
  dp[idx][val] = 0;
  for (int i = val; i <= 9; ++i) {
    dp[idx][val] += go(idx + 1, i);
  }
  return dp[idx][val];
}

int main() {
  int _;
  scanf("%d", &_);
  while (_--) {
    int t, n;
    scanf("%d %d", &t, &n);
    memset(dp, -1, sizeof dp);
    for (int i = 0; i <= 9; ++i) {
      dp[n - 1][i] = 1;
    }
    long long ans = 0;
    for (int i = 0; i <= 9; ++i) {
      ans += go(0, i);
    }
    printf("%d %lld\n", t, ans);
  }
  return 0;
}