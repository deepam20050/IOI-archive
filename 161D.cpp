// http://codeforces.com/problemset/problem/161/D

#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 1;

vector < int > g[N];
long long dp1[N][501];
long long ans;
int n, k;

void dfs1 (int x, int p) {
  dp1[x][0] = 1;
  for (int to : g[x]) {
    if (to != p) {
      dfs1(to, x);
    }
  }
  for (int to : g[x]) {
    if (to == p) {
      continue;
    }
    for (int i = 0; i < k; ++i) {
      ans += dp1[to][i] * dp1[x][k - i - 1];
    }
    for (int i = 1; i <= k; ++i) {
      dp1[x][i] += dp1[to][i - 1];
    }
  }
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1, a, b; i < n; ++i) {
    scanf("%d %d", &a, &b);
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  dfs1(1, -1);
  printf("%lld\n", ans);
  return 0;
}