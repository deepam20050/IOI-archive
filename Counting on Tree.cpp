// https://www.hackerearth.com/problem/algorithm/counting-on-tree-1/

#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 1;
const long long mod = 1e9 + 7;

vector <int> g[N];
long long dp[N][110];
long long tmp[110];
bool arr[N];
long long ans;
int n, k;

void dfs (int x, int p) {
  dp[x][arr[x]] = 1;
  for (int to : g[x]) {
    if (to == p) {
      continue;
    }
    dfs(to, x);
    for (int i = 0; i <= k; ++i) {
      tmp[i] = dp[x][i];
    }
    for (int i = 0; i <= k; ++i) {
      for (int j = 0; j <= k - i; ++j) {
        tmp[i + j] += dp[to][i] * dp[x][j] % mod;
        tmp[i + j] %= mod;
      }
    }
    for (int i = 0; i <= k; ++i) {
      dp[x][i] = tmp[i];
    }
  }
  ans += dp[x][k];
  ans %= mod;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    scanf("%d %d", &n, &k);
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; ++i) {
      g[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", arr + i);
    }
    for (int i = 1; i < n; ++i) {
      int x, y;
      scanf("%d %d", &x, &y);
      g[x].emplace_back(y);
      g[y].emplace_back(x);
    }
    ans = 0;
    dfs(1, -1);
    printf("%lld\n", ans);
  }
  return 0;
}