// http://codeforces.com/problemset/problem/19/D

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;
const int SN = 1 << 19;

set <int> t[SN];
int mx[SN];
char s[N][8];
int x[N];
int y[N];
int sorted[N];
unordered_map <int, int> pos;
unordered_map <int, int> pos_;

int n, x0;

void add (int nk, int l, int r, int x, int y) {
  if (l == r) {
    t[nk].insert(y);
    int val = *t[nk].rbegin();
    mx[nk] = val;
    return;
  }
  int m = l + r >> 1;
  if (x <= m) {
    add(nk << 1, l, m, x, y);
  } else {
    add(nk << 1 | 1, m + 1, r, x, y);
  }
  mx[nk] = max(mx[nk << 1], mx[nk << 1 | 1]);
}

void rem (int nk, int l, int r, int x, int y) {
  if (l == r) {
    auto it = t[nk].find(y);
    auto it2 = t[nk].erase(it);
    if (t[nk].empty()) {
      mx[nk] = -1;
    } else {
      mx[nk] = *t[nk].rbegin();
    }
    return;
  }
  int m = l + r >> 1;
  if (x <= m ) {
    rem(nk << 1, l, m, x, y);
  } else {
    rem(nk << 1 | 1, m + 1, r, x, y);
  }
  mx[nk] = max(mx[nk << 1], mx[nk << 1 | 1]);
}

int query (int nk, int l, int r, int x, int y, int h) {
  if (mx[nk] < h) {
    return -1;
  }
  if (l == r) {
    x0 = pos_[l];
    return *t[nk].lower_bound(h);
  }
  int m = l + r >> 1;
  int lft = nk << 1;
  int rgt = lft | 1;
  int ans = -1;
  if (x <= m) {
    ans = query(lft, l, m, x, y, h);
  }
  if (ans == -1 && y > m) {
    ans = query(rgt, m + 1, r, x, y, h);
  }
  return ans;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s %d %d", s[i], x + i, y + i);
    sorted[i] = x[i];
  }
  sort(sorted, sorted + n);
  int sz = 0;
  for (int i = 0; i < n; ++i) {
    if (!pos[sorted[i]]) {
      pos[sorted[i]] = sz;
      pos_[sz] = sorted[i];
      ++sz;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (s[i][0] == 'a') {
      add(1, 0, sz - 1, pos[x[i]], y[i]);
     } else if (s[i][0] == 'r') {
      rem(1, 0, sz - 1, pos[x[i]], y[i]);
    } else {
      x0 = -1;
      if (pos[x[i]] + 1 >= sz) {
        puts("-1");
        continue;
      }
      int y0 = query(1, 0, sz - 1, pos[x[i]] + 1, sz - 1, y[i] + 1);
      if (y0 == -1) {
        puts("-1");
      } else {
        printf("%d %d\n", x0, y0);
      }
    }
  }
  return 0;
}