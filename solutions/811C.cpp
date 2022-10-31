// http://codeforces.com/contest/811/problem/C
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

int a[N];
int first[N], last[N];
int dp[N];
bool used[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    last[a[i]] = i;
  }
  for (int i = n - 1; i >= 0; --i) {
    first[a[i]] = i;
  } 
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    if (last[a[i]] != i) {
      dp[i + 1] = dp[i];
    } else {
      for (int j = 0; j < N; ++j) {
        used[j] = 0;
      }
      int mi = first[a[i]];
      bool valid = 1;
      for (int j = i; valid && j >= mi; --j) {
        if (last[a[j]] > i) {
          valid = 0;
        }
        used[a[j]] = 1;
        mi = min(mi, first[a[j]]);
      }
      if (valid) {
        int ans = 0;
        for (int j = 0; j < N; ++j) {
          if (used[j]) {
            ans ^= j;
          }
        }
        dp[i + 1] = max(dp[i], ans + dp[mi]);
      } else {
        dp[i + 1] = dp[i];
      }
    }
  }
  printf("%d\n", dp[n]);
  return 0;
}

