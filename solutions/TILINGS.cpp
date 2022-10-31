// http://opc.iarcs.org.in/index.php/problems/TILINGS
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 1000010, mod = 10000;

int dp[N][2];

int main() {
  int n;
  scanf("%d", &n);
  dp[0][0] = 1;
  dp[0][1] = 1;
  dp[1][1] = 1;
  for (int i = 2; i <= n; ++i) {
    // 0
    dp[i][0] += dp[i - 2][1];
    dp[i][0] %= mod;
    if (i - 2 >= 1) {
      dp[i][0] += dp[i - 2][0] + dp[i - 3][1];      
      dp[i][0] %= mod;
    }
    // 1
    dp[i][1] += dp[i - 1][1];
    dp[i][1] %= mod;
    dp[i][1] += dp[i - 2][1];
    dp[i][1] %= mod;
    if (i - 2 >= 1) {
      dp[i][1] += dp[i - 2][0] + dp[i - 3][1];
      dp[i][1] %= mod;
      dp[i][1] += dp[i - 1][0];
      dp[i][1] %= mod;
    }
  }
  printf("%d\n", dp[n][1]);
  return 0;
}

