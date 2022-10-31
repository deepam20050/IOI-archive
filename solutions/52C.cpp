// http://codeforces.com/contest/52/problem/C

#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

long long t[4 * N];
long long lazy[4 * N];
long long arr[N];
int inp[3];

void push (int i, int l, int r) {
  t[i] += lazy[i];
  if (l < r) {
    lazy[i << 1] += lazy[i];
    lazy[i << 1 | 1] += lazy[i];
  }
  lazy[i] = 0;
}

void build (int i, int l, int r) {
  if (l == r) {
    t[i] = arr[l];
    return;
  }
  int m = (l + r) >> 1;
  build(i << 1, l, m);
  build(i << 1 | 1, m + 1, r);
  t[i] = min(t[i << 1], t[i << 1 | 1]);
}

long long query (int i, int l, int r, int x, int y) {
  push(i, l, r);
  if (x <= l && r <= y) {
    return t[i];
  }
  int m = (l + r) >> 1;
  long long ans = 1e18;
  if (x <= m) {
    ans = min(ans, query(i << 1, l, m, x, y));
  } 
  if (y > m) {
    ans = min(ans, query(i << 1 | 1, m + 1, r, x, y));
  }
  return ans;
}

void update (int i, int l, int r, int x, int y, long long add) {
  push(i, l, r);
  if (x <= l && r <= y) {
    lazy[i] += add;
    return;
  }
  int m = (l + r) >> 1;
  if (x <= m) {
    update(i << 1, l, m, x, y, add);
  }
  if (y > m) {
    update(i << 1 | 1, m + 1, r, x, y, add);
  }
  push(i << 1, l, m);
  push(i << 1 | 1, m + 1, r);
  t[i] = min(t[i << 1], t[i << 1 | 1]);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", arr + i);
  }
  build(1, 0, n - 1);
  int q;
  scanf("%d", &q);
  while (q--) {
    inp[2] = -1e9;
    int i = 0;
    char ch;
    do {
      scanf("%d%c", &inp[i], &ch);
      ++i;
      if (i >= 3) {
        break;
      }
    } while (ch != '\n');
    int l = inp[0], r = inp[1];
    if (l <= r) {
      if (inp[2] == -1e9) {
        printf("%lld\n", query(1, 0, n - 1, l, r));
      } else {
        update(1, 0, n - 1, l, r, inp[2]);
      }
    } else {
      if (inp[2] == -1e9) {
        printf("%lld\n", min(query(1, 0, n - 1, 0, r), query(1, 0, n - 1, l, n - 1)));
      } else {
        update(1, 0, n - 1, 0, r, inp[2]);
        update(1, 0, n - 1, l, n - 1, inp[2]);
      }
    }
  }
  return 0;
}