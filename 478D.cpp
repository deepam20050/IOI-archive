// http://codeforces.com/problemset/problem/478/D

#include <bits/stdc++.h>

using namespace std;

const int N = 200010, mod = 1e9 + 7;

int dp[N];

int calc(int x) {
  return (x * (x + 1)) / 2;
}

int main() {
  int r, g, h;
  scanf("%d %d", &r, &g);
  for (int i = 1;; ++i) {
    if (calc(i) > r + g) {
      h = i - 1;
      break;
    }   
  }
  dp[0] = 1;
  for (int i = 1; i <= h; ++i) {
    for (int j = r; j >= 0; --j) {
      if (j >= i) {
        dp[j] = (dp[j] + dp[j - i]) % mod;
      }
    }
  }
  int ans = 0, maxo = calc(h);
  for (int i = 0; i <= r; ++i) {
    if (i + g >= maxo) {
      ans = (ans + dp[i]) % mod;
    }
  }
  printf("%d\n", ans);
  return 0;
}

