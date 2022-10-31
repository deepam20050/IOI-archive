// https://www.codechef.com/problems/NPLFLC

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

long long bit[N];
long long ar[N];

int n;

void update(int idx, long long add) {
  long long rem = ar[idx];
  ar[idx] = add;
  while (idx <= n) {
    bit[idx] += add - rem;
    idx += idx & -idx;
  }
}

long long query(int idx) {
  long long res = 0;
  while (idx) {
    res += bit[idx];
    idx -= idx & -idx;
  }
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    long long x;
    scanf("%lld", &x);
    update(i, x);
  }
  int q;
  scanf("%d", &q);
  long long sum = query(n);
  while (q--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int x;
      long long y;
      scanf("%d %lld", &x, &y);
      update(x, y);
      sum = query(n);
    } else {
      long long z;
      scanf("%lld", &z);
      int l = 1, r = n;
      bool ok = 0;
      for (int i = 0; i < 17; ++i) {
        int m = (l + r) >> 1;
        long long target = sum - query(m);
        if (target == z) {
          ok = 1;
          break;
        } else if (target > z) {
          l = m + 1;
        } else {
          r = m - 1;
        }
      }
      ok ? puts("YES") : puts("NO");
    }
  }
  return 0;
}