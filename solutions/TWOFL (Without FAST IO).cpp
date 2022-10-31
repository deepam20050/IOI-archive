// https://www.codechef.com/JUNE18B/problems/TWOFL
// 3.99 seconds out of 4 *Gulps*

#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 2;
const int M = 4e6 + 2;
const int oo = 1 << 29;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int arr[N][N];
int color[N][N];
int n;
int m;
int clr_idx;
int ed_idx;
int clr_cnt[M];
vector < pair < pair < int, int >, pair < int, int > > > edge;
bool vis[N][N];
bool used[M];
int p[M];
int ans[M];
int sz[M];
int cnt;
int fst;
int lst;
int res;
int where[M];
int curr;

inline bool check (int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < m;
}

void dfs1 (int x, int y) {
  color[x][y] = clr_idx;
  ++cnt;
  for (int i = 0; i < 4; ++i) {
    int x0 = x + dx[i], y0 = y + dy[i];
    if (check(x0, y0) && arr[x0][y0] == arr[x][y] && !color[x0][y0]) {
      dfs1(x0, y0);
    }
  }
}

void dfs2 (int x, int y) {
  vis[x][y] = 1;
  for (int i = 0; i < 4; ++i) {
    int x0 = x + dx[i], y0 = y + dy[i];
    if (check(x0, y0)) {
      if (arr[x0][y0] != arr[x][y]) {
        edge.push_back({{min(arr[x0][y0], arr[x][y]), max(arr[x0][y0], arr[x][y])}, {min(color[x0][y0], color[x][y]), max(color[x0][y0], color[x][y])}});
      }
      if (arr[x0][y0] == arr[x][y] && !vis[x0][y0]) {
        dfs2(x0, y0);
      }
    }
  }
}

inline void build () {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", arr[i] + j);
    }
  }
  clr_idx = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
     if (!color[i][j]) {
        cnt = 0;
        dfs1(i, j);
        clr_cnt[clr_idx] = cnt;
        p[clr_idx] = clr_idx;
        sz[clr_idx] = 1;
        ans[clr_idx] = cnt;
        res = max(res, cnt);
        ++clr_idx;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!used[color[i][j]]) {
        dfs2(i, j);
      }
    }
  }
  sort(edge.begin(), edge.end());
}

inline int find_set (int x) {
  return p[x] == x ? x : p[x] = find_set(p[x]);
}

inline void join (int x, int y) {
  if (where[x] != curr) {
    p[x] = x;
    sz[x] = 1;
    ans[x] = clr_cnt[x];
    where[x] = curr;
  }
  if (where[y] != curr) {
    p[y] = y;
    sz[y] = 1;
    ans[y] = clr_cnt[y];
    where[y] = curr;
  }
  x = find_set(x);
  y = find_set(y);
  if (x == y) {
    return;
  }
  if (sz[x] < sz[y]) {
    swap(x, y);
  }
  sz[x] += sz[y];
  ans[x] += ans[y];
  p[y] = x;
  res = max(ans[x], res);
}

int main() {
  build();
  int a = -1;
  int b = -1;
  fst = 0;
  lst = -1;
  curr = 1;
  edge.push_back({{oo, oo}, {oo, oo}});
  ed_idx = edge.size();
  for (int i = 0; i < ed_idx; ++i) {
    int clr_a = edge[i].first.first;
    int clr_b = edge[i].first.second;
    int u = edge[i].second.first;
    int v = edge[i].second.second;
    if (clr_a == a && clr_b == b) {
      join(u, v);
      lst = i;  
      continue;
    }
    fst = i;
    lst = i;
    a = clr_a;
    b = clr_b;
    ++curr;
    if (i + 1 != ed_idx) {
      join(u, v);
    }
  }
  printf("%d\n", res);
  return 0;
}