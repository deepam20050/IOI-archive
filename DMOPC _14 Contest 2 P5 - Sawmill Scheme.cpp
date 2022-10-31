// https://dmoj.ca/problem/dmopc14c2p5

#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

vector <int> g[N];

double res[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  while (m--) {
    int x, y;
    scanf("%d %d", &x, &y);
    g[x].emplace_back(y);
  }
  res[1] = 1.0;
  for (int i = 1; i <= n; ++i) {
    for (int to : g[i]) {
      res[to] += (double) res[i] / g[i].size();
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (g[i].empty()) {
      printf("%.9f\n", res[i]);
    }
  }
  return 0;
}