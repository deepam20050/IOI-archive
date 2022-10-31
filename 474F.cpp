#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
const int SQN = 500;

int arr[N];
int l[N];
int r[N];
int gcds[N];
int n, q;

int gcd (int a, int b) {
  int c;
  while (b) {
    c = b;
    b = a % b;
    a = c;
  }
  return a;
}

struct segtree {
  int t[4 * N];

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
  int query (int nk, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
      return t[nk];
    }
    int m = l + r >> 1;
    int res = 0;
    if (x <= m) {
      res = query(nk << 1, l, m, x, y);
    }
    if (y > m) {
      res = gcd(res, query(nk << 1 | 1, m + 1, r, x, y));
    }
    return res;   
  }
} tree;


struct sqrt_d {
  int t[500][N];

  void build (int blck) {
    int l = blck * SQN;
    int r = min(l + SQN, q);
    while (l < r) {
      for (int i = 0; i < q; ++i) {
        t[blck][i] += (gcds[i] == arr[l]);
      }
      ++l;
    }
  }
  int query (int l, int r, int idx) {
    int blck_l = l / SQN;
    int blck_r = r / SQN;
    if (blck_l == blck_r) {
      int ans = 0;
      while (l <= r) {
        ans += gcds[idx] == arr[l++];
      }
      return ans;
    }
    int ans = 0;
    for (int i = l, end = (blck_l + 1) * SQN; i < end; ++i) {
      ans += gcds[idx] == arr[i];
    }
    for (int i = blck_r * SQN; i <= r; ++i) {
      ans += gcds[idx] == arr[i];
    }
    ++blck_l;
    while (blck_l < blck_r) {
      ans += t[blck_l++][idx];
    }
    return ans;
  }
} sqrt_;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
  }
  tree.build(1, 0, n - 1);
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    scanf("%d %d", l + i, r + i);
    --l[i];
    --r[i];
    gcds[i] = tree.query(1, 0, n - 1, l[i], r[i]);
  }
  int blocks = q / SQN;
  for (int i = 0; i <= blocks; ++i) {
    sqrt_.build(i);
  }
  for (int i = 0; i < q; ++i) {
    int num = sqrt_.query(l[i], r[i], i);
    printf("%d\n", r[i] - l[i] - num + 1);
  }
  return 0;
}