// http://codeforces.com/problemset/problem/743/D

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;
const long long oo = 1LL << 60;

long long arr[N];
long long sum[N];
long long dp[N];
vector < int > g[N];
long long ans = -oo;

void dfs1 (int x, int p) {
  for (int to : g[x]) {
    if (to != p) {
      dfs1(to, x);
    }
  }
  sum[x] = arr[x];
  long long _f = -oo, _s = -oo;
  for (int to : g[x]) {
    if (to == p) {
      continue;
    }
    sum[x] += sum[to];
    if (dp[to] > _s) {
      _s = dp[to];
    }
    if (_s > _f) {
      swap(_s, _f);
    }
  }
  dp[x] = max(_f, sum[x]);
  if (_f != -oo && _s != -oo) {
    ans = max(ans, _f + _s);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", arr + i);
  }
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }
  dfs1(1, -1);
  if (ans == -oo) {
    puts("Impossible");
  } else {
    printf("%lld", ans);
  }
  return 0;
}