// https://www.codechef.com/ICOP1902/problems/VIJJUPAR

#include <bits/stdc++.h>

using namespace std;

const int N = 123;
const long long MOD = 1e9 + 9;

long long dp[N][N];
int brr[N];
int n;
int k;

long long f (int idx, int lft) {
  if (idx == 0) {
    return lft == 0;
  }
  if (dp[idx][lft] != -1) {
    return dp[idx][lft];
  }
  dp[idx][lft] = 0;
  for (int i = 0; i <= brr[idx] && lft - i >= 0; ++i) {
    dp[idx][lft] += f(idx - 1, lft - i);
    dp[idx][lft] %= MOD;
  }
  return dp[idx][lft];
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; ++i) {
      scanf("%d", brr + i);
    }
    memset(dp, -1, sizeof dp);
    printf("%lld\n", f(k, n));
  }
  return 0;
}