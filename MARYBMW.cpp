// http://www.spoj.com/problems/MARYBMW/

#include <bits/stdc++.h>

using namespace std;

const int N = 50010;

vector <pair <int, long long>> g[N];
priority_queue <pair <long long, int>> pq;
long long max_speed[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      g[i].clear();
      max_speed[i] = -1LL;
    }
    while (m--) {
      int a, b;
      long long w;
      scanf("%d %d %lld", &a, &b, &w);
      g[a].push_back({b, w});
      g[b].push_back({a, w});
    }
    pq.push({1LL << 62, 1});
    max_speed[1] = 1LL << 62;
    while (!pq.empty()) {
      int u = pq.top().second;
      pq.pop();
      for (auto &e : g[u]) {
        int to = e.first;
        long long w = e.second;
        if (max_speed[to] < min(max_speed[u], w)) {
          max_speed[to] = min(max_speed[u], w);
          pq.push({max_speed[to], to});
        }
      }
    }
    printf("%lld\n", max_speed[n]);
  }
  return 0;
}