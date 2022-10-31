// https://dmoj.ca/problem/ccc12s1

#include <bits/stdc++.h>

using namespace std;

const int N = 99;

long long dp[100][4];

int main() {
  for (int i = 1; i <= N; ++i) {
    dp[i][0] = 1;
  }
  for (int i = 1; i <= N; ++i) {
    for (int k = 1; k <= 3; ++k) {
      for (int j = i - 1; j >= 1; --j) {
        dp[i][k] += dp[j][k - 1];
      }
    }
  }
  int x;
  scanf("%d", &x);
  printf("%lld\n", dp[x][3]);
  return 0;
}