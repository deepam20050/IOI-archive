// http://www.spoj.com/problems/DCEPC501/
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N];
long long dp[N];

int main() {

  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    memset(a, 0, sizeof a);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    memset(dp, 0, sizeof dp);
    for (int i = n - 1; i >= 0; --i) {
      long long d = a[i] + dp[i + 2];
      long long b = a[i] + a[i + 1] + dp[i + 4];
      long long c = a[i] + a[i + 1] + a[i + 2] + dp[i + 6];
      dp[i] = max(d, max(b, c));
    }
    printf("%lld\n", dp[0]);
  }
  return 0;
}

