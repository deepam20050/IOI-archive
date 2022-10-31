// http://codeforces.com/contest/920/problem/F

#include <bits/stdc++.h>

using namespace std;

const int N = 3e5;
const long long M = 1e6 + 1;

struct node {
  int mx;
  long long sum;
  node () {
    mx = 0;
    sum = 0LL;
  }
};

node t[4 * N];
int arr[N];
int sp[M];
int d[M];

node join (const node &a, const node &b) {
  node res;
  res.mx = max(a.mx, b.mx);
  res.sum = a.sum + b.sum;
  return res;
}

void build (int i, int l, int r) {
  if (l == r) {
    t[i].mx = t[i].sum = arr[l];
    return;
  }
  int m = (l + r) >> 1;
  build(i << 1, l, m);
  build(i << 1 | 1, m + 1, r);
  t[i] = join(t[i << 1], t[i << 1 | 1]);
}

void update (int i, int l, int r, int x, int y) {
  if (l == r) {
    t[i].mx = t[i].sum = d[t[i].mx];
    return;
  }
  int m = (l + r) >> 1;
  int lft = i << 1;
  int rgt = lft | 1;
  if (x <= m && t[lft].mx > 2) {
    update(lft, l, m, x, y);
  }
  if (y > m && t[rgt].mx > 2) {
    update(rgt, m + 1, r, x, y);
  }
  t[i] = join(t[lft], t[rgt]);
}

long long query (int i, int l, int r, int x, int y) {
  if (x <= l && r <= y) {
    return t[i].sum;
  }
  int m = (l + r) >> 1;
  long long res = 0;
  if (x <= m) {
    res += query(i << 1, l, m, x, y);
  }
  if (y > m) {
    res += query(i << 1 | 1, m + 1, r, x, y);
  }
  return res;
}

int main() {
  for (long long i = 2; i < M; ++i) {
    if (sp[i]) {
      continue;
    }
    sp[i] = i;
    for (long long j = i * i; j < M; j += i) {
      if (!sp[j]) {
        sp[j] = i;
      }
    }
  }
  d[1] = 1;
  for (int i = 2; i < M; ++i) {
    d[i] = 1;
    int x = i;
    int lst = sp[x];
    int cnt = 0;
    while (x > 1) {
      if (lst != sp[x]) {
        d[i] *= cnt + 1;
        cnt = 1;
        lst = sp[x];
      } else {
        ++cnt;
      }
      x /= sp[x];
    }
    d[i] *= cnt + 1;
  }
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
  }
  build(1, 0, n - 1);
  while (m--) {
    int type, l, r;
    scanf("%d %d %d", &type, &l, &r);
    --l;
    --r;
    --type;
    if (!type) {
      update(1, 0, n - 1, l, r);
    } else {
      printf("%lld\n", query(1, 0, n - 1, l, r));
    }
  }
  return 0;
}