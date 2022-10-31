// http://www.spoj.com/problems/SQRBR/

#include <bits/stdc++.h>

using namespace std;

int dp[50][50];
bool yes[50];

int n, k;

int solve(int idx, int open) {
  if (open < 0) {
    return 0;
  }
  if (idx == n + n) {
    return (open == 0);
  }
  int &ref = dp[idx][open];
  if (ref != -1) {
    return ref;
  }
  if (yes[idx]) {
    return ref = solve(idx + 1, open + 1);
  }
  return ref = solve(idx + 1, open + 1) + solve(idx + 1, open - 1);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &k);
    memset(dp, -1, sizeof dp);
    memset(yes, 0, sizeof yes);
    while (k--) {
      int x;
      scanf("%d", &x);
      yes[x - 1] = 1;
    }
    printf("%d\n", solve(0, 0));
  }
  return 0;
}