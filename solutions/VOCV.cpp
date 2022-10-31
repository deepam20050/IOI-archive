// http://www.spoj.com/problems/VOCV/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 11;
const int mod = 10007;

vector <int> g[N];
int dp[N][2];
int ways[N][2];

void dfs (int x, int p) {
  ways[x][0] = 1;
  ways[x][1] = 1;
  dp[x][1] = 1;
  for (int to : g[x]) {
    if (to == p) {
      continue;
    }
    dfs(to, x);
    if (dp[to][1] > dp[to][0]) {
      ways[x][1] *= ways[to][0];
    } else if (dp[to][1] < dp[to][0]) {
      ways[x][1] *= ways[to][1];
    } else {
      ways[x][1] *= ways[to][1] + ways[to][0];
    }
    ways[x][0] *= ways[to][1];
    dp[x][0] += dp[to][1];
    dp[x][1] += min(dp[to][1], dp[to][0]);
    ways[x][1] %= mod;
    ways[x][0] %= mod;
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      g[i].clear();
    }
    memset(dp, 0, sizeof dp);
    memset(ways, 0, sizeof ways);
    for (int i = 1; i < n; ++i) {
      int x, y;
      scanf("%d %d", &x, &y);
      g[x].emplace_back(y);
      g[y].emplace_back(x);
    }
    dfs(1, -1);
    int ans1 = min(dp[1][1], dp[1][0]);
    int ans2 = 0;
    if (dp[1][1] == dp[1][0]) {
      ans2 = ways[1][0] + ways[1][1];
    } else if (dp[1][1] < dp[1][0]) {
      ans2 = ways[1][1];
    } else {
      ans2 = ways[1][0];
    }
    printf("%d %d\n", ans1, ans2 % mod);
  }
  return 0;
}