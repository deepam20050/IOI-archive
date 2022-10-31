// https://codeforces.com/problemset/problem/1105/C

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long MOD = 1e9 + 7;

long long dp[N][3];

int main() {
  int n;
  long long l, r;
  scanf("%d %lld %lld", &n, &l, &r);
  long long zero = r / 3 - l / 3 + (l % 3 == 0);
  long long one = (r + 2) / 3 - (l + 2) / 3 + (l % 3 == 1);
  long long two = (r + 1) / 3 - (l + 1) / 3 + (l % 3 == 2);
  dp[0][0] = zero;
  dp[0][1] = one;
  dp[0][2] = two;
  for (int i = 1; i < n; ++i) {
    dp[i][0] = (zero * dp[i - 1][0] % MOD + one * dp[i - 1][2] % MOD + two * dp[i - 1][1] % MOD) % MOD;
    dp[i][1] = (zero * dp[i - 1][1] % MOD + one * dp[i - 1][0] % MOD + two * dp[i - 1][2]) % MOD;
    dp[i][2] = (zero * dp[i - 1][2] % MOD + two * dp[i - 1][0] % MOD + one * dp[i - 1][1] % MOD) % MOD;
  }
  printf("%lld", dp[n - 1][0]);
  return 0;
}