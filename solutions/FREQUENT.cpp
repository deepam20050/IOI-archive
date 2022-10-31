// http://www.spoj.com/problems/FREQUENT/

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

struct node {
  int m;
  int v;
  int l;
  int lv;
  int r;
  int rv;
  node () {
    m = 0;
    l = 0;
    r = 0;
    v = -2e9;
    lv = -2e9;
    rv = -2e9;
  }
};

node t[4 * N];
int a[N];

node join(const node &a, const node &b) {
  node res;
  if (a.m > b.m) {
    res.m = a.m;
    res.v = a.v;
  } else {
    res.m = b.m;
    res.v = b.v;
  }
  if (a.rv == b.lv && a.r + b.l > res.m) {
    res.m = a.r + b.l;
    res.v = a.rv;
  }
  res.l = a.l;
  res.r = b.r;
  res.lv = a.lv;
  res.rv = b.rv;
  if (res.lv == res.v) {
    res.l = res.m;
  }
  if (res.rv == res.v) {
    res.r = res.m;
  }
  return res;
}

void build(int i, int l, int r) {
  if (l == r) {
    t[i].m = 1;
    t[i].v = a[l];
    t[i].rv = a[l];
    t[i].lv = a[l];
    t[i].r = 1;
    t[i].l = 1;
    return;
  }
  int m = (l + r) >> 1;
  build(i << 1, l, m);
  build(i << 1 | 1, m + 1, r);
  t[i] = join(t[i << 1], t[i << 1 | 1]);
}

node query(int i, int l, int r, int x, int y) {
  if (x <= l && r <= y) {
    return t[i];
  }
  int m = (l + r) >> 1;
  node L, R;
  if (x <= m) {
    L = query(i << 1, l, m, x, y);
  }
  if (y > m) {
    R = query(i << 1 | 1, m + 1, r, x, y);
  }
  return join(L, R);
}

int main() {
  int n, q;
  while (scanf("%d", &n) && n && scanf("%d", &q)) {
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    build(1, 0, n - 1);
    while (q--) {
      int l, r;
      scanf("%d %d", &l, &r);
      printf("%d\n", query(1, 0, n - 1, l - 1, r - 1).m);
    }
  }
  return 0;
}