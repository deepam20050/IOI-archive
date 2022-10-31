#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6e4;
const int M = 2e5 + 5;
const int K = 17;

int tin[N];
int height[N];
int ETT[N << 1];
pair < int, int > ST[N << 1][K];
int p[N];
int size[N];
vector < int > g[N];
vector < int > at[N];
vector < pair < int, pair < int, int > > > Q[N];
int timer;
int n;
int m;
int lg[N];
int print[M];
void dfs1 (int x, int p, int h = 0) {
  tin[x] = ++timer;
  height[x] = h;
  ETT[timer] = x;
  for (int to : g[x]) {
    if (to != p) {
      dfs1(to, x, h + 1);
      ETT[++timer] = x;
    }
  }
}

void computeST () {
  for (int i = 1; i <= timer; ++i) {
    ST[i][0] = {height[ETT[i]], ETT[i]};
  }
  for (int j = 1; j < K; ++j) {
    for (int i = 1; i + (1 << j) <= timer; ++i) {
      ST[i][j] = min(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
    }
  }
}

int lca (int u, int v) {
  int l = tin[u];
  int r = tin[v];
  if (l > r) {
    swap(l, r);
  }
  int j = lg[r - l + 1];
  return min(ST[l][j], ST[r - (1 << j) + 1][j]).second;
}

inline int find_parent (int x) {
  return p[x] == x ? x : p[x] = find_parent(p[x]);
}

inline void join (int x, int y) {
  x = find_parent(x);
  y = find_parent(y);
  if (x == y) {
    return;
  }
  if (size[x] < size[y]) {
    swap(x, y);
  }
  size[x] += size[y];
  p[y] = x;
}

void dfs2 (int x, int p) {
  for (int to : g[x]) {
    if (to != p) {
      dfs2(to, x);
      join(x, to);
    }
  }
  for (auto q : Q[x]) {
    int id = q.first;
    if (print[id] == 1) {
      continue;
    }
    int a = q.second.first;
    int b = q.second.second;
    int ok1 = find_parent(a) == find_parent(x);
    int ok2 = find_parent(b) == find_parent(x);
    if (ok1 + ok2 == 1 || lca(a, b) == x) {
      print[id] = 1;
    } else {
      print[id] = 0;
    }
  }
}

int main() {
  lg[1] = 0;
  for (int i = 2; i < N; ++i) {
    lg[i] = lg[i >> 1] + 1;
  }
  while (scanf("%d %d", &n, &m) != EOF) {
    for (int i = 0; i <= n; ++i) {
      g[i].clear();
      Q[i].clear();
      at[i].clear();
      p[i] = i;
      size[i] = 1;
    }
    memset(print, -1, sizeof print);
    for (int i = 1, num; i <= n; ++i) {
      scanf("%d", &num);
      at[num].emplace_back(i);
    }
    for (int i = 1, x, y; i < n; ++i) {
      scanf("%d %d", &x, &y);
      g[x].emplace_back(y);
      g[y].emplace_back(x);
    }
    for (int i = 0; i < m; ++i) {
      int x, y, z;
      scanf("%d %d %d", &x, &y, &z);
      for (int node : at[z]) {
        Q[node].push_back({i, {x, y}});
      }
    }
    timer = 0;
    dfs1(1, -1);
    computeST();
    dfs2(1, -1);
    for (int i = 0; i < m; ++i) {
      print[i] == 1 ? puts("Find") : puts("NotFind");
    }
  }
  return 0;
}