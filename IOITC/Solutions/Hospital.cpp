// AC

#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

const int N = 1e5 + 1;
const long long oo = 1e18;

vector < pair <int, long long> > g[N];
long long d[N];
priority_queue <pair <long long, int>> pq;

int main() {
  int n, m, h;
  scanf("%d %d %d", &n, &m, &h);
  fill(d, d + n + 2, oo);
  for (int i = 1; i <= h; ++i) {
    int x;
    scanf("%d", &x);
    pq.push({0, x});
    d[x] = 0;
  }
  for (int i = 0; i < m; ++i) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    g[x].push_back({y, z});
    g[y].push_back({x, z});
  }
  while (!pq.empty()) {
    auto top = pq.top();
    pq.pop();
    int x = top.second;
    for (auto e : g[x]) {
      int to = e.first;
      long long w = e.second;
      if (d[to] > d[x] + w) {
        d[to] = d[x] + w;
        pq.push({-d[to], to});
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (d[i]) {
      if (d[i] == oo) {
        d[i] = -1;
      }
      printf("%d %lld\n", i, d[i]);
    }
  }
  return 0;
}