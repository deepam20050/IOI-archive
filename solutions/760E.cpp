// http://codeforces.com/problemset/problem/760/E

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;

int arr[N];
int p[N];
int lzy[4 * N];
int t[4 * N];
int n;

void push (int nk, int l, int r) {
  if (lzy[nk]) {
    t[nk] += lzy[nk];
    if (l < r) {
      lzy[nk << 1] += lzy[nk];
      lzy[nk << 1 | 1] += lzy[nk];
    }
    lzy[nk] = 0;
  }
}

void update (int nk, int l, int r, int x, int y, int add) {
  push(nk, l, r);
  if (x <= l && r <= y) {
    lzy[nk] = add;
    return;
  }
  int m = l + r >> 1;
  if (x <= m) {
    update(nk << 1, l, m, x, y, add);
  }
  if (y > m) {
    update(nk << 1 | 1, m + 1, r, x, y, add);
  }
  push(nk << 1, l, m);
  push(nk << 1 | 1, m + 1, r);
  t[nk] = max(t[nk << 1], t[nk << 1 | 1]);
}

int query (int nk, int l, int r) {
  push(nk, l, r);
  if (t[nk] <= 0) {
    return -1;
  }
  if (l == r) {
    return arr[l];
  }
  int m = l + r >> 1;
  int res = query(nk << 1 | 1, m + 1, r);
  if (res == -1) {
    res = query(nk << 1, l, m);
  }
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int op;
    scanf("%d %d", p + i, &op);
    if (op) {
      int x;
      scanf("%d", &x);
      arr[p[i]] = x;
      update(1, 1, n, 1, p[i], 1);
    } else {
      update(1, 1, n, 1, p[i], -1);
    }
    printf("%d\n", query(1, 1, n));
  }
  return 0;
}