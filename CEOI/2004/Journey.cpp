// https://szkopul.edu.pl/problemset/problem/hGQ-dYNqYEu52ssZ6dtwRIGd/site/?key=statement

#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 1;

vector < pair < int, int > > g[N];
bool visit[N];
bool any[N];
int dp[N][2];
int n;
int root;

void dfs1 (int x, int p = -1) {
  if (visit[x]) {
    any[x] = 1;
  }
  int save = 0;
  for (auto &e : g[x]) {
    int to = e.first;
    int w = e.second;
    if (to == p) {
      continue;
    }
    dfs1(to, x);
    if (any[to]) {
      any[x] = 1;
      dp[x][0] += w + w + dp[to][0];
      save = max(save, w + dp[to][0] - dp[to][1]);
    }
  }
  dp[x][1] = dp[x][0] - save;
}

int main() {
  scanf("%d %d", &n, &root);
  for (int i = 1; i < n; ++i) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    g[x].push_back({y, z});
    g[y].push_back({x, z});
  }
  int zaga;
  scanf("%d", &zaga);
  for (int i = 0, x; i < zaga; ++i) {
    scanf("%d", &x);
    visit[x] = 1;
  }
  dfs1(root);
  printf("%d\n", dp[root][1]);
  return 0;
}