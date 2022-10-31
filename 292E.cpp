// http://codeforces.com/contest/292/problem/E

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;

struct data {
  int start;
  int quer;
  bool who;
  data () {
    start = 0;
    quer = 0;
    who = 0;
  }
};

data t[4 * N];
int arr[2][N];

void push (int nk, int l, int r) {
  if (t[nk].who && l < r) {
    int lft = nk << 1;
    int rgt = lft | 1;
    int m = l + r >> 1;
    if (t[lft].quer < t[nk].quer) {
      t[lft].start = t[nk].start;
      t[lft].who = 1; 
      t[lft].quer = t[nk].quer;
    }
    if (t[rgt].quer < t[nk].quer) {
      t[rgt].start = t[nk].start + m - l + 1; 
      t[rgt].who = 1; 
      t[rgt].quer = t[nk].quer;
    }
  }
}

void build (int nk, int l, int r) {
  if (l == r) {
    t[nk].who = 0;
    t[nk].start = l;
    return;
  }
  int m = l + r >> 1;
  build(nk << 1, l, m);
  build(nk << 1 | 1, m + 1, r);
}

void update (int nk, int l, int r, int x, int y, int k, int quer) {
  push(nk, l, r);
  if (y <= l && r <= y + k - 1) {
    t[nk].start = x + l - y;
    t[nk].who = 1;
    t[nk].quer = quer;
    push(nk, l, r);
    // cout << nk << " :: " << l << " " << r << " :::: " << t[nk].start << '\n';
    return;
  }
  int m = l + r >> 1;
  if (y <= m) {
    update(nk << 1, l, m, x, y, k, quer);
  }
  if (y + k - 1 > m) {
    update(nk << 1 | 1, m + 1, r, x, y, k, quer);
  }
}

int query (int nk, int l, int r, int x) {
  push(nk, l, r);
  if (l == r) {
    // cout << nk << " :: " << l << " " << r << " :::: " << t[nk].start << " " << t[nk].who << '\n';
    return arr[t[nk].who][t[nk].start];
  }
  int m = l + r >> 1;
  int res;
  if (x <= m) {
    res = query(nk << 1, l, m, x);
  } else {
    res = query(nk << 1 | 1, m + 1, r, x);
  }
  return res;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", arr[1] + i);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", arr[0] + i);
  }
  build(1, 1, n);
  for (int i = 1; i <= m; ++i) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int x, y, k;
      scanf("%d %d %d", &x, &y, &k);
      update(1, 1, n, x, y, k, i);
    } else {
      int x;
      scanf("%d", &x);
      printf("%d\n", query(1, 1, n, x));
    }
  }
  return 0;
}