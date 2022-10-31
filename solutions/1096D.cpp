#include <bits/stdc++.h>

using namespace std;

int main() {
  scanf("%d", &n);
  scanf("%s", str + 1);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", arr + i);
  }
  for (int i = 1; i <= n; ++i) {
    fill(dp[i], dp[i] + 4, 1LL << 50);
  }
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (str[i] == hard[j]) {
        dp[i][j] = min(dp[i - 1][j - 1], arr[i] + dp[i - 1][j])       
      }
    }
  }
  return 0;
}