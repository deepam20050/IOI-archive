// http://codeforces.com/contest/631/problem/C

#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int a[N], t[N], r[N], z[N], mp[N];
deque <int> d;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  int sz = -1, idx = -1;
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", t + i, r + i);
    if (r[i] >= sz) {
      idx = i;
      sz = r[i];
    }
  }
  sort(a + 1, a + sz + 1);
  for (int i = 1; i <= sz; ++i) {
    d.push_back(a[i]);
  }
  for (int i = idx + 1; i < m; ++i) {
    mp[r[i]] = i;
  }
  int curr = t[idx];
  memset(z, -1 ,sizeof z);
  for (int i = n; i >= 1; --i) {
    if (mp[i] > idx) {
      z[i + 1] = curr;
      curr = t[mp[i]];
      idx = mp[i];
    }
    if (mp[i] == m - 1) {
      z[1] = curr;
    }
  }
  int now = z[1];
  for (int i = 1; i <= sz; ++i) {
    if (z[i] != -1) {
      now = z[i];
    }
    z[i] = now;
  }
  for (int i = sz; i >= 1; --i) {
    if (z[i] == 1) {
      z[i] = d.back();
      d.pop_back();
    } else {
      z[i] = d.front();
      d.pop_front();
    }
  }
  for (int i = sz + 1; i <= n; ++i) {
    z[i] = a[i];
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d ", z[i]);
  }
  return 0;
}