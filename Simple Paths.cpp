// https://csacademy.com/contest/archive/task/simple-paths/solution/
// Mehnat and lagan se sab kuch mumkin hai

#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

vector <int> g[N];
int used[N];
int p[N];
bool ok[N][N];

int u;
int v;

void dfs(int x, int mark) {
  used[x] = 1;
  for (int to : g[x]) {
    if ((x == u && to == v) || (x == v && to == u)) {
      continue;
    }
    if (!used[to]) {
      dfs(to, mark);
    }
  }
}

int get(int x, int y) {
  memset(used, 0, sizeof used);
  queue <int> q;
  q.push(x);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int to : g[u]) {
      if (!used[to]) {
        q.push(to);
        used[to] = 1;
        p[to] = u;
      }
    }
  }
  for (int i = y; i != x; i = p[i]) {
    if (!ok[p[i]][i]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }
  int comp = 0;
  for (int i = 1, mark = 1; i <= n; ++i) {
    if (!used[i]) {
      dfs(i, mark++);
      ++comp;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int to : g[i]) {
      u = i;
      v = to;
      int delta = 0;
      memset(used, 0, sizeof used);
      for (int j = 1, mark = 1; j <= n; ++j) {
        if (!used[j]) {
          dfs(j, mark++);
          ++delta;
        }
      }
      if (delta > comp) {
        ok[i][to] = 1;
      }
    }
  }
  while (q--) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (used[x] != used[y]) {
      printf("0\n");
    } else {
      printf("%d\n", get(x, y));
    }
  }
  return 0;
}