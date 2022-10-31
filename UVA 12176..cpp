// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=&problem=3328&mosmsg=Submission+received+with+ID+20447705

#include <bits/stdc++.h>

using namespace std;

const int N = 3010;

bool used[N];
int p[N];
int size[N];
pair <int, pair <int, int>> e[123456];
vector < pair <int, int> > g[N];

int who;
int ans;

void dfs(int x, int dist) {
  used[x] = 1;
  if (who == x) {
    ans = dist;
    return;
  }
  for (auto &e : g[x]) {
    int to = e.first, w = e.second;
    if (!used[to]) {
      dfs(to, max(dist, w));
    }
  }
}

int find_set(int x) {
  return p[x] == x ? x : (p[x] = find_set(p[x]));
}

void join(int a, int b) {
  int x = find_set(a), y = find_set(b);
  if (size[x] < size[y]) {
    swap(x, y);
  }
  p[y] = x;
  size[x] += size[y];
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; ++tt) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      p[i] = i;
      size[i] = 1;
      g[i].clear();
    }
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      e[i] = {c, {a, b}};
    }
    sort(e, e + m);
    int cnt;
    for (int i = 0; i < m; ++i) {
      int from = e[i].second.first, to = e[i].second.second;
      if (find_set(from) != find_set(to)) {
        join(from, to);
        g[from].push_back({to, e[i].first});
        g[to].push_back({from, e[i].first});
        ++cnt;
      }
    }
    printf("Case %d\n", tt);
    int q;
    scanf("%d", &q);
    while (q--) {
      int a, b;
      scanf("%d %d", &a, &b);
      memset(used, 0, sizeof used);
      who = b;
      dfs(a, -1);
      printf("%d\n", ans);
    }
    puts("");
  }
  return 0;
}