// https://www.codechef.com/problems/QSET

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

struct node {
  long long ans;
  long long rems[3];
  int s;
  node () {
    ans = 0;
    s = 0;
    memset(rems, 0, sizeof rems);
  }
};

node t[4 * N];
char s[N];
int a[N];

node join(const node &a, const node &b) {
  node res;
  res.s = (a.s + b.s) % 3;
  res.ans = a.ans + b.ans;
  for (int i = 0; i < 3; ++i) {
    res.rems[i] += a.rems[i];
    int r = (a.s + i) % 3;
    res.rems[r] += b.rems[i];
  }
  for (int i = 0; i < 3; ++i) {
    int r = (a.s + i) % 3;
    res.ans += b.rems[i] * (r == a.s ? a.rems[r] - 1 : a.rems[r]);
    res.ans += r ? 0 : b.rems[i];
  }
  return res;
}

void build(int i, int l, int r) {
  if (l == r) {
    t[i].s = a[l] % 3;
    t[i].ans = !(a[l] % 3);
    t[i].rems[a[l] % 3] = 1;
    return;
  }
  int m = (l + r) >> 1;
  build(i << 1, l, m);
  build(i << 1 | 1, m + 1, r);
  t[i] = join(t[i << 1], t[i << 1 | 1]);
}

void update(int i, int l, int r, int x) {
  if (l == r) {
    t[i].s = a[l] % 3;
    t[i].ans = a[l] % 3 ? 0 : 1;
    memset(t[i].rems, 0, sizeof t[i].rems);
    t[i].rems[a[l] % 3] = 1;
    return;
  }
  int m = (l + r) >> 1;
  if (x <= m) {
    update(i << 1, l, m, x);
  } else {
    update(i << 1 | 1, m + 1, r, x);
  }
  t[i] = join(t[i << 1], t[i << 1 | 1]);
}

node query(int i, int l, int r, int x, int y) {
  if (x <= l && r <= y) {
    return t[i];
  }
  node L, R;
  int m = (l + r) >> 1;
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
  scanf("%d %d", &n, &q);
  scanf("%s", s);
  for (int i = 0; i < n; ++i) {
    a[i] = s[i] - '0';
  }
  build(1, 0, n - 1);
  while (q--) {
    int ty, x, y;
    scanf("%d %d %d", &ty, &x, &y);
    if (ty == 1) {
      a[x - 1] = y;
      update(1, 0, n - 1, x - 1);
    } else {
      printf("%lld\n", query(1, 0, n - 1, x - 1, y - 1).ans);
    }
  }
  return 0;
}