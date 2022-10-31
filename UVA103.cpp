// https://uva.onlinejudge.org/external/1/p103.pdf

#include <bits/stdc++.h>

using namespace std;

const int N = 123;

int p[N];
int dp[N];
int a[N][N];
stack <int> s;

int n;
int k;

int go(int idx) {
  if (dp[idx] != -1) {
    return dp[idx];
  }
  dp[idx] = 1;
  for (int i = 0; i < n; ++i) {
    if (idx == i) {
      continue;
    }
    bool ok = 1;
    for (int j = 0; j < k; ++j) {
      if (a[idx][j] <= a[i][j]) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      int t = go(i) + 1;
      if (t > dp[idx]) {
        p[idx] = i;
        dp[idx] = t;
      }
    }
  }
  return dp[idx];
}

int main() {
  while (scanf("%d %d", &n, &k) != EOF) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < k; ++j) {
        scanf("%d", a[i] + j);
      }
      sort(a[i], a[i] + k);
    }
    memset(p, -1, sizeof p);
    memset(dp, -1, sizeof dp);
    int mx = -1;
    for (int i = 0; i < n; ++i) {
      mx = max(mx, go(i));
    }
    for (int i = 0; i < n; ++i) {
      if (dp[i] == mx) {
        for (int j = i; j != -1; j = p[j]) {
          s.push(j + 1);
        }
        break;
      }
    }
    printf("%d\n", mx);
    while (!s.empty()) {
      printf("%d ", s.top());
      s.pop();
    }
    puts("");
  }
  return 0;
}