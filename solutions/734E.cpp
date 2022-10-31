#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;

vector < int > g[N];
bool arr[N];
int dp[N][2];

void dfs1 (int x, int p) {
  dp[x][arr[x] ^ 1] = 1;
  for (int to : g[x]) {
    if (to == p) {
      continue;
    }
    dfs1(to, x);
    if (arr[x]) {
      if (arr[to]) {
        dp[x][1] += dp[to][1];
        dp[x][0] += dp[to][0] - 1;
      } else {
        dp[x][1] += dp[to][1];
        dp[x][0] += dp[to][0];
      }
    } else {
      if (arr[to]) {
        dp[x][0] += dp[to][0];
        dp[x][1] += dp[to][1];
      } else {
        dp[x][0] += dp[to][0];
        dp[x][1] += dp[to][1] - 1;
      }
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", arr + i);
  }
  for (int i = 1, x, y; i < n; ++i) {
    scanf("%d %d", &x, &y);
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }
  dfs1(1, -1);
  printf("%d", min(dp[1][0], dp[1][1]));
  return 0;
}