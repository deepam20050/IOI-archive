// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/little-deepu-and-array/

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

struct node {
  int val;
  int lazy;
  node () {
    val = 0;
    lazy = 0;
  }
};

node t[4 * N];
pair <int, int> inp[N];
int arr[N];
int ans[N];

int n;

void push(int i, int l, int r) {
  t[i].val -= t[i].lazy;
  if (l < r) {
    t[i << 1].lazy += t[i].lazy;
    t[i << 1 | 1].lazy += t[i].lazy;
  }
  t[i].lazy = 0;
}

node join(const node &a, const node &b) {
  node res;
  res.val = a.val;
  return res;
}

void build(int i, int l, int r) {
  if (l == r) {
    t[i].val = arr[l];
    return;
  }
  int m = (l + r) >> 1;
  build(i << 1, l, m);
  build(i << 1 | 1, m + 1, r);
  t[i] = join(t[i << 1], t[i << 1 | 1]);
}

int query(int i, int l, int r, int x) {
  push(i, l, r);
  if (l == r) {
    return t[i].val;
  }
  int m = (l + r) >> 1;
  if (x <= m) {
    return query(i << 1, l, m, x);
  } else {
    return query(i << 1 | 1, m + 1, r, x);
  }
  return -1;
}

void update(int i, int l, int r, int x, int y) {
  push(i, l, r);
  if (x <= l && r <= y) {
    ++t[i].lazy;
    return;
  }
  int m = (l + r) >> 1;
  if (x <= m) {
    update(i << 1, l, m, x, y);
  }
  if (y > m) {
    update(i << 1 | 1, m + 1, r, x, y);
  }
  push(i << 1, l, m);
  push(i << 1 | 1, m + 1, r);
  t[i] = join(t[i << 1], t[i << 1 | 1]);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &inp[i].first);
    inp[i].second = i;
  }
  sort(inp, inp + n);
  for (int i = 0; i < n; ++i) {
    arr[i] = inp[i].first;
  }
  build(1, 0, n - 1);
  int q;
  scanf("%d", &q);
  while (q--) {
    int x;
    scanf("%d", &x);
    int l = 0, r = n - 1;
    int pos = -1;
    for (int i = 0; i < 20; ++i) {
      int m = (l + r) >> 1;
      int val = query(1, 0, n - 1, m);
      if (val > x) {
        pos = m;
        r = m;
      } else {
        l = m + 1;
      }
    }
    if (pos != -1) {
      update(1, 0, n - 1, pos, n - 1);
    }
  }
  for (int i = 0; i < n; ++i) {
    ans[inp[i].second] = query(1, 0, n - 1, i);
  }
  for (int i = 0; i < n; ++i) {
    printf("%d ", ans[i]);
  }
  return 0;
}