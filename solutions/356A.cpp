// http://codeforces.com/contest/356/problem/A

#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 1;

int l[N];
int r[N];
int x[N];
int lzy[4 * N];
int t[4 * N];
int n, m;

void push (int nk, int l, int r) {
  if (lzy[nk]) {
    t[nk] = lzy[nk];
    if (l < r) {
      lzy[nk << 1] = lzy[nk];
      lzy[nk << 1 | 1] = lzy[nk];
    }
    lzy[nk] = 0;
  }
}

void update (int nk, int l, int r, int x, int y, int who) {
  if (x > y) {
    return;
  }
  push(nk, l, r);
  if (x <= l && r <= y) {
    lzy[nk] = who;
    return;
  }
  int m = l + r >> 1;
  if (x <= m) {
    update(nk << 1, l, m, x, y, who);
  }
  if (y > m) {
    update(nk << 1 | 1, m + 1, r, x, y, who);
  }
  push(nk << 1, l, m);
  push(nk << 1 | 1, m + 1, r);
}

int query (int nk, int l, int r, int x) {
  push(nk, l, r);
  if (l == r) {
    return t[nk];
  }
  int m = l + r >> 1;
  int ret = 0;
  if (x <= m) {
    ret = query(nk << 1, l, m, x);
  } else {
    ret = query(nk << 1 | 1, m + 1, r, x);
  }
  return ret;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = m - 1; i >= 0; --i) {
    scanf("%d %d %d", l + i, r + i, x + i);
  }
  for (int i = 0; i < m; ++i) {
    update(1, 1, n, l[i], x[i] - 1, x[i]);
    update(1, 1, n, x[i] + 1, r[i], x[i]);
  }
  for (int i = 1; i <= n; ++i) {
    if (x[0] == i) {
      printf("0 ");
    } else {
      printf("%d ", query(1, 1, n, i));
    }
  }
  return 0;
}