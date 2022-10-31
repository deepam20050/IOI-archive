// http://codeforces.com/problemset/problem/109/C

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;

vector < pair < int, int > > g[N];
int size[N];
int good1[N];
int good2[N];
int n;

bool yes (int x) {
  while (x) {
    int val = x % 10;
    if (val != 4 && val != 7) {
      return 0;
    }
    x /= 10;
  }
  return 1;
}

void dfs1 (int x, int p) {
  size[x] = 1;
  for (auto &e : g[x]) {
    int to = e.first;
    int w = e.second;
    if (to == p) {
      continue;
    }
    dfs1(to, x);
    size[x] += size[to];
    good1[x] += good1[to] + yes(w) * (size[to] - good1[to]);
  }
}

void dfs2 (int x, int p, int sum) {
  good2[x] += sum;
  sum += good1[x];
  for (auto &e : g[x]) {
    int to = e.first;
    int w = e.second;
    if (to == p) {
      continue;
    }
    bool chck = yes(w);
    if (chck) {
      int tmp = sum;
      sum = n - size[to];
      dfs2(to, x, sum);
      sum = tmp;
    } else {
      sum -= good1[to];
      dfs2(to, x, sum);
      sum += good1[to];
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0, x, y, z; i < n - 1; ++i) {
    scanf("%d %d %d", &x, &y, &z);
    g[x].push_back({y, z});
    g[y].push_back({x, z});
  }
  dfs1(1, -1);
  dfs2(1, -1, 0);
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    long long total = good1[i] + good2[i];
    ans += total * (total - 1);
  }
  printf("%lld", ans);
  return 0;
}