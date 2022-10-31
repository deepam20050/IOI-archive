// AC

#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5 + 1;
const int M = 1e6 + 1;

int p[N];
int sz[N];
bool yes[N];
bool leaf[N];
pair < int, pair < int, int > > edges[M];
int n, m, k;

int find_p (int x) {
  return p[x] == x ? x : p[x] = find_p(p[x]);
}

void join (int a, int b) {
  int x = find_p(a);
  int y = find_p(b);
  if (sz[x] < sz[y]) {
    swap(x, y);
  }
  sz[x] += sz[y];
  p[y] = x;
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0, x; i < k; ++i) {
    scanf("%d", &x);
    yes[x] = 1;
    leaf[x] = 1;
  }
  long long ans = 0;
  for (int i = 0; i < m; ++i) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    if (n == 2) {
      printf("%d\n", z);
      return 0;
    }
    edges[i] = {z, {x, y}};
  }
  for (int i = 1; i <= n; ++i) {
    p[i] = i;
    sz[i] = 1;
  }
  sort(edges, edges + m);
  for (int i = 0; i < m; ++i) {
    int w = edges[i].first;
    int u = edges[i].second.first;
    int v = edges[i].second.second;
    if (yes[u] && yes[v]) continue;
    if (find_p(u) == find_p(v)) continue;
    if (!yes[u] && !yes[v]) {
      ans += w;
      join(u, v);
      continue;
    }
    if (leaf[u] == 1) {
      ans += w;
      leaf[u] = 0;
      join(u, v);
      continue;
    }
    if (leaf[v] == 1) {
      ans += w;
      leaf[v] = 0;
      join(u, v);
    }
  }
  printf("%lld", ans);
  return 0;
}