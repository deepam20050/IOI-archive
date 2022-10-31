// http://codeforces.com/contest/914/problem/D

#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 1;

int t[4 * N];
int arr[N];
int n, x, y, g, cnt;

int gcd (int a, int b) {
  int c;
  while (b) {
    c = b;
    b = a % b;
    a = c;
  }
  return a;
}

void build (int nk, int l, int r) {
  if (l == r) {
    t[nk] = arr[l];
    return;
  }
  int m = l + r >> 1;
  build(nk << 1, l, m);
  build(nk << 1 | 1, m + 1, r);
  t[nk] = gcd(t[nk << 1], t[nk << 1 | 1]);
}

void update (int nk, int l, int r) {
  if (l == r) {
    t[nk] = y;
    return;
  }
  int m = l + r >> 1;
  if (x <= m) {
    update(nk << 1, l, m);
  } else {
    update(nk << 1 | 1, m + 1, r);
  }
  t[nk] = gcd(t[nk << 1], t[nk << 1 | 1]);
}

void query (int nk, int l, int r) {
  if (l == r) {
    cnt += t[nk] != g;
    return;
  }
  int m = l + r >> 1;
  if (x <= m && t[nk << 1] % g) {
    query(nk << 1, l, m);
  }
  if (cnt > 1) {
    return;
  }
  if (y > m && t[nk << 1 | 1] % g) {
    query(nk << 1 | 1, m + 1, r);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", arr + i);
  }
  build(1, 1, n);
  int q;
  scanf("%d", &q);
  while (q--) {
    int op;
    scanf("%d", &op);
    if (op == 2) {
      scanf("%d %d", &x, &y);
      update(1, 1, n);
    } else {
      scanf("%d %d %d", &x, &y, &g);
      cnt = 0;
      query(1, 1, n);
      puts(cnt > 1 ? "NO" : "YES");
    }
  }
  return 0;
}