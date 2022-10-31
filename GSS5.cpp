// http://www.spoj.com/problems/GSS5/

#include <bits/stdc++.h>

using namespace std;

const int N = 10010;
const int oo = -(1 << 20);

struct node {
  int sum;
  int pref;
  int suf;
  int best;
  node () {
    sum = 0;
    pref = 0;
    suf = 0;
    best = 0;
  }
};

node t[4 * N];
int arr[N];

node join (const node &a, const node &b) {
  node res;
  res.sum = a.sum + b.sum;
  res.best = max(a.best, b.best);
  res.best = max(res.best, a.suf + b.pref);
  res.pref = max(a.pref, a.sum + b.pref);
  res.suf = max(b.suf, b.sum + a.suf);
  return res;
}

void build (int i, int l, int r) {
  if (l == r) {
    t[i].sum = arr[l];
    t[i].pref = arr[l];
    t[i].suf = arr[l];
    t[i].best = arr[l];
    return;
  }
  int m = l + r >> 1;
  build(i << 1, l, m);
  build(i << 1 | 1, m + 1, r);
  t[i] = join(t[i << 1], t[i << 1 | 1]);
}

node query (int i, int l, int r, int x, int y) {
  if (x > y) {
    return t[0];
  }
  if (x <= l && r <= y) {
    return t[i];
  }
  int m = l + r >> 1;
  node res;
  res.best = oo;
  res.suf = oo;
  res.pref = oo;
  res.sum = 0;
  if (x <= m) {
    res = query(i << 1, l, m, x, y);
  }
  if (y > m) {
    res = join(res, query(i << 1 | 1, m + 1, r, x, y));
  }
  return res;
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", arr + i);
    }
    build(1, 1, n);
    int q;
    scanf("%d", &q);
    while (q--) {
      int x1, y1, x2, y2;
      scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
      int ans = 0;
      if (y1 < x2) {
        ans = query(1, 1, n, x1, y1).suf + query(1, 1, n, y1 + 1, x2 - 1).sum + query(1, 1, n, x2, y2).pref;
      } else {
        ans = query(1, 1, n, x1, y1).suf + query(1, 1, n, y1 + 1, y2).pref;
        ans = max(ans, query(1, 1, n, x1, x2 - 1).suf + query(1, 1, n, x2, y2).pref);
        ans = max(ans, query(1, 1, n, x2, y1).best);
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}