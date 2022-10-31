#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 18;
const int mod = 10007;

struct node {
  int a;
  int b;
  int c;
  node () {
    a = 0;
    b = 0;
    c = 0;
  }
};


node lazy[N];
int t[N];

int sqr (int n) {
  return ((n % mod * (n + 1) % mod * (n + n + 1) % mod) / 6) % mod;
}

int sum (int n) {
  return ((n % mod * (n + 1) % mod) / 2) % mod;
}

int modd (int x) {
  return (x % mod + mod) % mod;
}

void push (int i, int l, int r) {
  t[i] = (t[i] % mod + lazy[i].a * modd(sqr(r) - sqr(l - 1)) % mod + lazy[i].b * modd(sum(r) - sum(l - 1)) % mod + lazy[i].c * (r - l + 1) % mod) % mod;
  if (l < r) {
    int lft = i << 1;
    int rgt = lft | 1;
    lazy[lft].a += lazy[i].a;
    lazy[lft].b += lazy[i].b;
    lazy[lft].c += lazy[i].c;
    lazy[rgt].a += lazy[i].a;
    lazy[rgt].b += lazy[i].b;
    lazy[rgt].c += lazy[i].c;
  }
  lazy[i].a = 0;
  lazy[i].b = 0;
  lazy[i].c = 0;
}

void update (int i, int l, int r, int x, int y, int a, int b, int c) {
  push(i, l, r);
  if (x <= l && r <= y) {
    lazy[i].a += a;
    lazy[i].b += b;
    lazy[i].c += c;
    lazy[i].a %= mod;
    lazy[i].b %= mod;
    lazy[i].c %= mod;
    return;
  }
  int m = (l + r) >> 1;
  if (x <= m) {
    update(i << 1, l, m, x, y, a, b, c);
  }
  if (y > m) {
    update(i << 1 | 1, m + 1, r, x, y, a, b, c);
  }
  push(i << 1, l, m);
  push(i << 1 | 1, m + 1, r);
  t[i] += t[i << 1] + t[i << 1 | 1];
  t[i] %= mod;
}

int query (int i, int l, int r, int x, int y) {
  push(i, l, r);
  if (x <= l && r <= y) {
    return t[i];
  }
  int m = (l + r) >> 1;
  int res = 0;
  if (x <= m) {
    res += query(i << 1, l, m, x, y);
  }
  if (y > m) {
    res += query(i << 1 | 1, m + 1, r, x, y);
  }
  return res % mod;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  while (m--) {
    int tt;
    scanf("%d", &tt);
    if (tt) {
      int x, y;
      scanf("%d %d", &x, &y);
      printf("%d\n", query(1, 0, n - 1, x, y));
    } else {
      int x, y, a, b, c;
      scanf("%d %d %d %d %d", &x, &y, &a, &b, &c);
      update(1, 0, n - 1, x, y, a, b, c);
    }
  }
  return 0;
}