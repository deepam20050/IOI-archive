// http://codeforces.com/contest/903/problem/D

#include <bits/stdc++.h>

using namespace std;
using l = long double;

const int N = 200010;

l a[N];
l b[N];
l c[N];

struct Fenwick {
  l t[N];

  void update(int n, int idx, l add) {
    while (idx < n) {
      t[idx] += add;
      idx = idx | (idx + 1);
    }
  }
  l query(int idx) {
    l ans = 0;
    while (idx >= 0) {
      ans += t[idx];
      idx = (idx & (idx + 1)) - 1;
    }
    return ans;
  }
};

Fenwick sum, cnt;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b, b + n);
  const int m = unique_copy(b, b + n, c) - c;
  l ans = 0;
  for (int i = 0; i < n; ++i) {
    int at = lower_bound(c, c + m, a[i]) - c;
    int p1 = at, p2 = at;
    sum.update(m, at, a[i]);
    cnt.update(m, at, 1);
    while (p1 < m && c[p1] - c[at] <= 1) {
      ++p1;
    }
    while (p2 >= 0 && c[at] - c[p2] <= 1) {
      --p2;
    }
    if (p1 < m) {
      l howmany = cnt.query(m - 1) - cnt.query(p1 - 1);
      l s = sum.query(m - 1) - sum.query(p1 - 1);
      ans += howmany * a[i] - s;
    }
    if (p2 >= 0) {
      l howmany = cnt.query(p2);
      l s = sum.query(p2);
      ans += howmany * a[i] - s;
    }
  }
  printf("%.0Lf",ans);
  return 0;
}