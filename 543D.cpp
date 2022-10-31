#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;
const long long mod = 1e9 + 7;

vector <int> g[N];
long long dp[N][2];
long long ans[N];

void dfs1 (int x, int p) {
  if (g[x].size() == 1) {
    dp[x][0] = 1;
    dp[x][1] = 1;
  }
  for (int to : g[x]) {
    if (to == p) {
      continue;
    }
    dfs1(to, x);
    dp[x][0] += dp[to][1];
    dp[x][1] += dp[to][1] + dp[to][0];
    dp[x][0] %= mod;
    dp[x][1] %= mod;
  }
}

void dfs2 (int x, int p, long long sum0, long long sum1) {
  ans[x] = dp[x][0] + dp[x][1] + sum0 + sum1;
  ans[x] %= mod;
  sum0 += dp[x][0];
  sum1 += dp[x][1];
  for (int to : g[x]) {
    if (to == p) {
      continue;
    }
    sum0 -= dp[to][0];
    sum1 -= dp[to][1];
    sum0 %= mod;
    sum0 += mod;
    sum0 %= mod;
    sum1 %= mod;
    sum1 += mod;
    sum1 %= mod;
    dfs2(to, x, sum0, sum1);
    sum0 += dp[to][0];
    sum1 += dp[to][1];
    sum0 %= mod;
    sum1 %= mod;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 2; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    g[i].emplace_back(x);
    g[x].emplace_back(i);
  }
  dfs1(1, -1);
  dfs2(1, -1, 0, 0);
  for (int i = 1; i <= n; ++i) {
    printf("%lld ", ans[i]);
  }
  return 0;
}