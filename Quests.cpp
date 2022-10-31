#include <bits/stdc++.h>

using namespace std;

long long f (int idx, int lft) {
  
}

int main() {
  scanf("%d %d", &n, &H);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d %d %d", g + i, h + i, q + i, t + i);
  }
  for (int i = 1; i <= H; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (h[j] <= i) {
        dp1[i] = max(dp1[i], g[i] + dp1[i - h[j]]);
      }
    }
  }
  return 0;
}