// http://www.spoj.com/problems/LOSTNSURVIVED/

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

set < pair <int, int> > s;
int p[N], size[N];

int find_set(int x) {
  return p[x] == x ? x : (p[x] = find_set(p[x]));
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; ++i) {
    p[i] = i;
    size[i] = 1;
    s.insert({1, i});
  }
  while (q--) {
    int a, b;
    scanf("%d %d", &a, &b);
    int x = find_set(a), y = find_set(b);
    if (x == y) {
      printf("%d\n", s.rbegin()->first - s.begin()->first);
      continue;
    }
    if (size[x] < size[y]) {
      swap(x, y);
    }
    auto it = s.erase({size[y], y});
    it = s.erase({size[x], x});
    size[x] += size[y];
    p[y] = x;
    s.insert({size[x], x});
    printf("%d\n", s.rbegin()->first - s.begin()->first);
  }
  return 0;
}