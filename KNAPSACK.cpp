// http://www.spoj.com/problems/KNAPSACK/

#include <bits/stdc++.h>

using namespace std;

const int N = 2010;

int s[N];
int c[N];
int dp[N];
int t[N];

int main() {
  int w, n;
  scanf("%d %d", &w, &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", s + i, c + i);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= w; ++j) {
      t[j] = dp[j];
    }
    for (int j = 1; j <= w; ++j) {
      if (s[i] <= j) {
        dp[j] = max(dp[j], t[j - s[i]] + c[i]);
      }
    }
  }
  printf("%d", dp[w]);
  return 0;
}