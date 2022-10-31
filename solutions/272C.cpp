// http://codeforces.com/problemset/problem/272/C

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

long long arr[N];
long long t[4 * N];
long long lzy[4 * N];
int n, m;

void push (int i, int l, int r) {
  if (lzy[i]) {
    t[i] = lzy[i];
    if (l < r) {
      lzy[i << 1] = lzy[i];
      lzy[i << 1 | 1] = lzy[i];
    }
  }
  lzy[i] = 0;
}

void build (int i, int l, int r) {
  if (l == r) {
    t[i] = arr[l];
    return;
  }
  int m = l + r >> 1;
  build(i << 1, l, m);
  build(i << 1 | 1, m + 1, r);
  t[i] = max(t[i << 1], t[i << 1 | 1]);
}

void update (int i, int l, int r, int x, int y, long long val) {
  push(i, l, r);
  if (x <= l && r <= y) {
    lzy[i] = val;
    return;
  }
  int m = l + r >> 1;
  if (x <= m) {
    update(i << 1, l, m, x, y, val);
  }
  if (y > m) {
    update(i << 1 | 1, m + 1, r, x, y, val);
  }
  push(i << 1, l, m);
  push(i << 1 | 1, m + 1, r);
  t[i] = max(t[i << 1], t[i << 1 | 1]);
}

long long query (int i, int l, int r, int x, int y) {
  push(i, l, r);
  if (x <= l && r <= y) {
    return t[i];
  }
  int m = l + r >> 1;
  long long ans = -1;
  if (x <= m) {
    ans = max(ans, query(i << 1, l, m, x, y));
  }
  if (y > m) {
    ans = max(ans, query(i << 1 | 1, m + 1, r, x, y));
  }
  return ans;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", arr + i);
  }
  build(1, 0, n - 1);
  scanf("%d", &m);
  while (m--) {
    int w, h;
    scanf("%d %d", &w, &h);
    --w;
    long long hh = query(1, 0, n - 1, 0, w);
    printf("%lld\n", hh);
    update(1, 0, n - 1, 0, w, hh + h);
  }
  return 0;
}