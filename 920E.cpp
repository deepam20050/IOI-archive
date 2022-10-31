// http://codeforces.com/problemset/problem/920/E

#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

set <int> g[N];
set <int> unused;
int size[N];

int cnt;

void dfs (int x) {
  unused.erase(x);
  ++size[cnt];
  int curr = -1;
  while (1) {
    auto it = unused.upper_bound(curr);
    if (it == unused.end()) {
      break;
    }
    curr = *it;
    if (g[x].count(curr)) {
      continue;
    }
    dfs(curr);
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  while (m--) {
    int x, y;
    scanf("%d %d", &x, &y);
    g[x].insert(y);
    g[y].insert(x);
  }
  for (int i = 1; i <= n; ++i) {
    unused.insert(i);
  }
  for (int i = 1; i <= n; ++i) {
    if (unused.count(i)) {
      ++cnt;
      dfs(i);
    }
  }
  printf("%d\n", cnt);
  sort(size + 1, size + cnt + 1);
  for (int i = 1; i <= cnt; ++i) {
    printf("%d ", size[i]);
  }
  return 0;
}