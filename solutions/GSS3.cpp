// http://www.spoj.com/problems/GSS3/

#include <bits/stdc++.h>

using namespace std;

const int N = 50010;
const int oo = -(1 << 20);

struct node {
  int sum;
  int best;
  int pref;
  int suf;
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
  res.pref = max(a.pref, a.sum + b.pref);
  res.suf = max(b.suf, b.sum + a.suf);
  res.best = max(a.best, b.best);
  res.best = max(res.best, a.suf + b.pref);
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
  int m = (l + r) >> 1;
  build(i << 1, l, m);
  build(i << 1 | 1, m + 1, r);
  t[i] = join(t[i << 1], t[i << 1 | 1]);
}

void update (int i, int l, int r, int x, int y) {
  if (l == r) {
    t[i].sum = y;
    t[i].pref = y;
    t[i].suf = y;
    t[i].best = y;
    return;
  }
  int m = (l + r) >> 1;
  if (x <= m) {
    update(i << 1, l, m, x, y);
  } else {
    update(i << 1 | 1, m + 1, r, x, y);
  }
  t[i] = join(t[i << 1], t[i << 1 | 1]);
}

node query (int i, int l, int r, int x, int y) {
  if (x <= l && r <= y) {
    return t[i];
  }
  int m = (l + r) >> 1;
  node res;
  res.sum = 0;
  res.pref = oo;
  res.suf = oo;
  res.best = oo;
  if (x <= m) {
    res = query(i << 1, l, m, x, y);
  }
  if (y > m) {
    res = join(res, query(i << 1 | 1, m + 1, r, x, y));
  }
  return res;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", arr + i);
  }
  build(1, 1, n);
  int q;
  scanf("%d", &q);
  while (q--) {
    int tt, x, y;
    scanf("%d %d %d", &tt, &x, &y);
    if (tt) {
      printf("%d\n", query(1, 1, n, x, y).best);
    } else {
      update(1, 1, n, x, y);
    }
  }
  return 0;
}