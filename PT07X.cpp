// http://www.spoj.com/problems/PT07X/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;

vector <int> g[N];
int dp[N][2];

void dfs (int x, int p) {
  for (int to : g[x]) {
    if (to != p) {
      dfs(to, x);
    }
  }
  dp[x][1] = 1;
  for (int to : g[x]) {
    if (to == p) {
      continue;
    }
    dp[x][1] += min(dp[to][0], dp[to][1]);
    dp[x][0] += dp[to][1];
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }
  dfs(1, -1);
  printf("%d\n", min(dp[1][1], dp[1][0]));
  return 0;
}