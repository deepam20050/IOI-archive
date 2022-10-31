// https://www.codechef.com/problems/CSUBQ

#include <bits/stdc++.h>

using namespace std;

const int N = 2000010;

struct node {
  long long ans;
  long long misuf;
  long long mipref;
  long long mxpref;
  long long mxsuf;
  int size;
  bool big;
  node () {
    ans = 0;
    mipref = 0;
    misuf = 0;
    mxpref = 0;
    mxsuf = 0;
    size = 0;
    big = 0;
  }
};

node t[N];

int n;
int q;
int L;
int R;

node join (const node &a, const node &b) {
  node res;
  res.size = a.size + b.size;
  res.ans = a.ans + b.ans;
  res.ans += a.misuf * b.mxpref;
  res.ans += a.mxsuf * (b.mxpref + b.mipref);
  res.big = max(a.big, b.big);
  if (a.big) {
    res.mipref = a.mipref;
    res.mxpref = a.mxpref;
  } else {
    if (a.mipref == a.size) {
      res.mxpref = b.mxpref;
      res.mipref = a.mipref + b.mipref;
    } else {
      res.mxpref = a.mxpref + b.mipref + b.mxpref;
      res.mipref = a.mipref;
    }
  }
  if (b.big) {
    res.misuf = b.misuf;
    res.mxsuf = b.mxsuf;
  } else {
    if (b.misuf == b.size) {
      res.misuf = b.misuf + a.misuf;
      res.mxsuf = a.mxsuf;
    } else {
      res.mxsuf = b.mxsuf + a.misuf + a.mxsuf;
      res.misuf = b.misuf;
    }
  }
  return res;
}

void build (int i, int l, int r) {
  if (l == r) {
    t[i].mxpref = 0;
    t[i].mxsuf = 0;
    t[i].mipref = 1;
    t[i].misuf = 1;
    t[i].size = 1;
    t[i].ans = 0;
    t[i].big = 0;
    return;
  }
  int m = (l + r) >> 1;
  build(i << 1, l, m);
  build(i << 1 | 1, m + 1, r);
  t[i] = join(t[i << 1], t[i << 1 | 1]);
}

void update (int i, int l, int r, int x, int y) {
  if (l == r) {
    if (y > R) {
      t[i].mxsuf = 0;
      t[i].misuf = 0;
      t[i].mipref = 0;
      t[i].mxpref = 0;
      t[i].size = 1;
      t[i].ans = 0;
      t[i].big = 1;
    } else if (y < L) {
      t[i].mxpref = 0;
      t[i].mxsuf = 0;
      t[i].misuf = 1;
      t[i].mipref = 1;
      t[i].size = 1;
      t[i].ans = 0;
      t[i].big = 0;
    } else {
      t[i].mxsuf = 1;
      t[i].mxpref = 1;
      t[i].mipref = 0;
      t[i].misuf = 0;
      t[i].size = 1;
      t[i].ans = 1;
      t[i].big = 0;
    }
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
  if (x <= m) {
    res = join(res, query(i << 1, l, m, x, y));
  } 
  if (y > m) {
    res = join(res, query(i << 1 | 1, m + 1, r, x, y));
  }
  return res;
}

int main() {
  scanf("%d %d %d %d", &n, &q, &L, &R);
  build(1, 1, n);
  while (q--) {
    int tt, l, r;
    scanf("%d %d %d", &tt, &l, &r);
    if (tt == 1) {
      update(1, 1, n, l, r);
    } else {
      printf("%lld\n", query(1, 1, n, l, r).ans);
    }
  }
  return 0;
}