// http://www.spoj.com/problems/FOXLINGS/

#include <bits/stdc++.h>

using namespace std;

unordered_map <int, int> p, size;

int find_set(int x) {
  return p[x] == x ? x : (p[x] = find_set(p[x]));
}

void join(int a, int b) {
  int x = find_set(a), y = find_set(b);
  if (x != y) {
    if (size[x] < size[y]) {
      swap(x, y);
    }
    p[y] = x;
    size[x] += size[y];
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  while (m--) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (!p[a]) {
      size[a] = 1;
      p[a] = a;
    }
    if (!p[b]) {
      size[b] = 1;
      p[b] = b;
    }
    join(a, b);
  }
  set <int> s;
  for (auto &e : p) {
    s.insert(find_set(e.first));
  }
  printf("%d\n", n - p.size() + s.size());
  return 0;
}