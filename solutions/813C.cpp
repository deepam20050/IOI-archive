// http://codeforces.com/problemset/problem/813/C

#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

vector <int> g[N];
bool used[N];
int da[N];
int db[N];
int path[N];
queue <int> q;

void compute(int x, int d[]) {
  memset(used, 0, sizeof used);
  q.push(x);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    used[u] = 1;
    for (int to : g[u]) {
      if (!used[to]) {
        d[to] = 1 + d[u];
        used[to] = 1;
        q.push(to);
      }
    }
  }
}

int dfs(int x) {
  used[x] = 1;
  for (int to : g[x]) {
    if (!used[to]) {
      path[x] = max(path[x], dfs(to));
    }
  }
  return ++path[x];
}

int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  for (int i = 1; i < n; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  compute(1, da);
  compute(x, db);
  memset(used, 0, sizeof used);
  dfs(1);
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    if (db[i] < da[i]) {
      res = max(res, (da[i] + path[i]) * 2 - 2);
    }
  }
  printf("%d\n", res);
  return 0;
}