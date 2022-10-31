// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/k-th-bit-faae0e0d/description/

#include <bits/stdc++.h>

using namespace std;

const int N =  1000010;

int t[4 * N];

void build (int i, int l, int r) {
  if (l == r) {
    t[i] = 1;
    return;
  }
  int m = (l + r) >> 1;
  build(i << 1, l, m);
  build(i << 1 | 1, m + 1, r);
  t[i] = t[i << 1] + t[i << 1 | 1];
}

void update (int i, int l, int r, int x) {
  if (l == r) {
    t[i] = 0;
    return;
  }
  int m = (l + r) >> 1;
  if (x <= m) {
    update(i << 1, l, m, x);
  } else {
    update(i << 1 | 1, m + 1, r, x);
  }
  t[i] = t[i << 1] + t[i << 1 | 1];
}

int query (int i, int l, int r, int x) {
  if (x < 0 || l > r) {
    return -1;
  }
  if (l == r && x == 1) {
    return l;
  }
  int m = (l + r) >> 1;
  int lval = t[i << 1];
  int rval = t[i << 1 | 1];
  if (x > lval) {
    return query(i << 1 | 1, m + 1, r, x - lval);
  } else {
    return query(i << 1, l, m, x);
  }
  return -1;
}

int main() {
  int n;
  scanf("%d", &n);
  build(1, 1, n);
  int q;
  scanf("%d", &q);
  while (q--) {
    int i, x;
    scanf("%d %d", &i, &x);
    if (!i) {
      update(1, 1, n, x);
    } else {
      printf("%d\n", query(1, 1, n, x));
    }
  }
  return 0;
}