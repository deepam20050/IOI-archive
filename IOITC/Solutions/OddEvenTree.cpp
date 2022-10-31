// AC

#include <cstdio>
#include <vector>

using namespace std;

const int N = 1e5 + 1;

vector <int> g[N];
long long dp[N][2][2];
long long out[N][2];

void dfs1 (int x, int p) {
  for (int to : g[x]) {
    if (to != p) {
      dfs1(to, x);  
    }
  }
  dp[x][0][0] = 1;
  for (int to : g[x]) {
    if (to == p) {
      continue;
    }
    dp[x][0][0] += dp[to][0][1];
    dp[x][0][1] += dp[to][0][0];
  }
  long long even = 0;
  long long odd = 0;
  for (int to : g[x]) {
    if (to == p) {
      continue;
    }
    dp[x][1][0] += even * dp[to][0][1] + odd * dp[to][0][0];
    dp[x][1][1] += even * dp[to][0][0] + odd * dp[to][0][1];
    even += dp[to][0][1];
    odd += dp[to][0][0];
  }
}

void dfs2 (int x, int p, long long even, long long odd) {
  out[x][0] = even;
  out[x][1] = odd;
  even += dp[x][0][0];
  odd += dp[x][0][1];
  for (int to : g[x]) {
    if (to == p) {
      continue;
    }
    even -= dp[to][0][1];
    odd -= dp[to][0][0];
    dfs2(to, x, odd, even);
    even += dp[to][0][1];
    odd += dp[to][0][0];
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  dfs1(1, -1);
  dfs2(1, -1, 0, 0);
  for (int i = 1; i <= n; ++i) {
    long long even = 0;
    long long odd = 0;
    for (int j = 0; j < 2; ++j) {
      even += dp[i][j][0];
      odd += dp[i][j][1];
    }
    even += out[i][1] * dp[i][0][1] + dp[i][0][0] * out[i][0];
    odd += out[i][1] * dp[i][0][0] + dp[i][0][1] * out[i][0];
    printf("%lld %lld\n", odd, even);
  }
  return 0;
}