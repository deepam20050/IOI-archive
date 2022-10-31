// http://codeforces.com/contest/936/problem/B

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int SEEN = 0;
const int LOSE = 1;
const int DRAW = 2;
const int WIN = 3;

vector <int> g[N];
int dp[N][2];
int nxt[N][2];

int n;
int m;
int s;

int dfs (int x, int p) {
  if (dp[x][p] != -1) {
    return dp[x][p];
  }
  if (g[x].empty()) {
    if (p == 0) {
      dp[x][p] = WIN;
    } else {
      dp[x][p] = LOSE;
    }
    return dp[x][p];
  }
  dp[x][p] = SEEN;
  for (int to : g[x]) {
    int res = dfs(to, p ^ 1);
    if (res == SEEN && DRAW > dp[x][p]) {
      dp[x][p] = DRAW;
      nxt[x][p] = to;
    } else if (res > dp[x][p]) {
      dp[x][p] = res;
      nxt[x][p] = to;
    }
  }
  return dp[x][p];
}

int main() {
  memset(dp, -1, sizeof dp);
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    int c;
    scanf("%d", &c);
    while (c--) {
      int x;
      scanf("%d", &x);
      g[i].emplace_back(x);
    }
  }
  scanf("%d", &s);
  int val = dfs(s, 1);
  if (val == WIN) {
    int p = 1;
    puts("Win");
    while (s) {
      printf("%d ", s);
      s = nxt[s][p];
      p ^= 1;
    }
  } else {
    puts(val == LOSE ? "Lose" : "Draw");
  }
  return 0;
}