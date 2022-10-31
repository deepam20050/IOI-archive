// http://codeforces.com/problemset/problem/916/C
// Easy problem with many corner cases! :D

#include <bits/stdc++.h>

using namespace std;

const int M = 1e6 + 10;
const int oo = 1e9;

bool p[M];
vector < pair <int, pair <int, int>> > g;
set < pair <int, int> > s;

inline void print() {
  for (const auto &e : g) {
    printf("%d %d %d\n", e.first, e.second.first, e.second.second);
  }
}

int main() {
  for (int i = 2; i * i < M; ++i) {
    if (!p[i]) {
      for (int j = i * i; j < M; j += i) {
        p[j] = 1;
      }
    }
  }
  int n, m;
  scanf("%d %d", &n, &m);
  s.insert({1, n});
  g.push_back({1, {n, 2}});
  if (m == 1) {
    puts("2 2");
    print();
    return 0;
  }
  g.push_back({n, {2, 1}});
  if (m == 2) {
    puts("2 3");
    print();
    return 0;
  }
  for (int i = 3; i <= n - 2; ++i) {
    g.push_back({i - 1, {i, 1}});
    s.insert({i - 1, i});
  }
  if (n == 3 && m == 3) {
    puts("2 3");
    g.push_back({n - 2, {n - 1, 1 << 15}});
    print();
    return 0;
  }
  for (int i = 2; i < M; ++i) {
    if (p[i]) {
      continue;
    }
    int x = i;
    if (x > n - 1) {
      g.push_back({n - 2, {n - 1, x - n + 1}});
      s.insert({n - 2, n - 1});
      printf("2 %d\n", x);
      break;
    }
  }
  s.insert({n, 2});
  int edges = n - 1;
  for (int i = 1; i <= n && edges < m; ++i) {
    for (int j = 1; j <= n && edges < m; ++j) {
      if (i != j && s.find({i, j}) == s.end() && s.find({j, i}) == s.end()) {
        ++edges;
        s.insert({i, j});
        g.push_back({i, {j, oo}});
      }
    }
  }
  print();
  return 0;
}