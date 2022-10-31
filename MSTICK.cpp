// https://www.codechef.com/problems/MSTICK

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

struct node {
  int mx;
  int mi;
};

node t[4 * N];
int a[N];

void build(int i, int l, int r) {
  if (l == r) {
    t[i].mx = a[l];
    t[i].mi = a[l];
    return;
  }
  int m = (l + r) >> 1;
  build(i << 1, l, m);
  build(i << 1 | 1, m + 1, r);
  t[i].mx = max(t[i << 1].mx, t[i << 1 | 1].mx);
  t[i].mi = min(t[i << 1].mi, t[i << 1 | 1].mi);
}

int query(int i, int l, int r, int x, int y, bool style) {
  if (x <= l && r <= y) {
    return style ? t[i].mx : t[i].mi;
  }
  int m = (l + r) >> 1;
  int res = style ? -1e9 : 1e9;
  if (x <= m) {
    style ? res = max(res, query(i << 1, l, m, x, y, style)) : res = min(res, query(i << 1, l, m, x, y, style));
  }
  if (y > m) {
    style ? res = max(res, query(i << 1 | 1, m + 1, r, x, y, style)) : res = min(res, query(i << 1 | 1, m + 1, r, x, y, style));
  }
  return res;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  build(1, 0, n - 1);
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    int mini = query(1, 0, n - 1, l, r, 0);
    int res1 = query(1, 0, n - 1, l, r, 1);
    int res2 = l == 0 ? -1e9 : query(1, 0, n - 1, 0, l - 1, 1);
    int res3 = r == n - 1 ? -1e9 : query(1, 0, n - 1, r + 1, n - 1, 1);
    double ans = max((double)(res1 - mini) / 2.0, max((double)res2, (double)res3)) + (double)mini;
    printf("%.1f\n",ans);
  }
  return 0;
}