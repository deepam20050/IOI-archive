// http://www.spoj.com/problems/ACTIV/

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const long long mod = 1e8;

pair <int, int> p[N];
int t[N];
long long dp[N];

int n;

long long go(int idx) {
  if (idx >= n) {
    return 0;
  }
  if (dp[idx] != -1) {
    return dp[idx];
  }
  return dp[idx] = (1 + go(lower_bound(t, t + n, p[idx].second) - t) + go(idx + 1)) % mod;
}

int main() {
  while (scanf("%d", &n) && n != -1) {
    for (int i = 0; i < n; ++i) {
      scanf("%d %d", &p[i].first, &p[i].second);
    }
    sort(p, p + n);
    for (int i = 0; i < n; ++i) {
      t[i] = p[i].first;
    }
    memset(dp, -1, sizeof dp);
    printf("%08lld\n", go(0));
  }
  return 0;
}