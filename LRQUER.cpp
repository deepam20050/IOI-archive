// https://www.codechef.com/problems/LRQUER

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

multiset <int> t[4 * N];
int arr[N];

long long L;
long long R;
int val;

void build (int i, int l, int r) {
  t[i].clear();
  for (int j = l; j <= r; ++j) {
    t[i].insert(arr[j]);
  }
  if (l == r) {
    return;
  }
  int m = (l + r) >> 1;
  build(i << 1, l, m);
  build(i << 1 | 1, m + 1, r);
}

long long eval (long long m) {
  return (m - L) * (R - m);
}

void update (int i, int l, int r, int x, int y) {
  auto it = t[i].find(arr[x]);
  t[i].erase(it);
  t[i].insert(y);
  if (l == r) {
    return;
  }
  int m = (l + r) >> 1;
  if (x <= m) {
    update(i << 1, l, m, x, y);
  } else {
    update(i << 1 | 1, m + 1, r, x, y);
  }
}

long long query (int i, int l, int r, int x, int y) {
  if (x > r || y < l) {
    return -1e18;
  }
  if (x <= l && r <= y) {
    auto it = t[i].upper_bound(val);
    long long ans = -1e18;
    if (it == t[i].end()) {
      --it;
      return eval(*it);
    } else if (it == t[i].begin()) {
      return eval(*it);
    } else {
      ans = max(ans, eval(*it));
      --it;
      ans = max(ans, eval(*it));
    }
    return ans;
  }
  long long ans = -1e18;
  int m = (l + r) >> 1;
  return max(query(i << 1, l, m, x, y), query(i << 1 | 1, m + 1, r, x, y));
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; ++i) {
      scanf("%d", arr + i);
    }
    build(1, 0, n - 1);
    while (q--) {
      int o, x, y;
      scanf("%d %d %d", &o, &x, &y);
      if (o == 1) {
        L = arr[x - 1];
        R = arr[y - 1];
        val = (L + R) >> 1;
        printf("%lld\n", query(1, 0, n - 1, x - 1, y - 1));
      } else {
        update(1, 0, n - 1, x - 1, y);
        arr[x - 1] = y;
      }
    }
  }
  return 0;
}