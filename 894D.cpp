// http://codeforces.com/contest/894/problem/D
// Nice problem

#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

vector <int> g[N];
vector <long long> s[N];
int to[2];
int l[N];

long long query (int x, long long h) {
  if (h <= 0) {
    return 0;
  }
  int idx = upper_bound(g[x].begin(), g[x].end(), h) - g[x].begin() - 1;
  return (idx + 1) * h - s[x][idx];
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 2; i <= n; ++i) {
    scanf("%d", l + i);
  }
  for (int i = n; i; --i) {
    g[i].emplace_back(0);
    to[0] = i + i;
    to[1] = i + i + 1;
    for (int x : to) {
      if (x > n) {
        continue;
      }
      for (int j : g[x]) {
        g[i].emplace_back(j + l[x]);
      }
    }
    sort(g[i].begin(), g[i].end());
    s[i].resize(g[i].size());
    for (int j = 1; j < s[i].size(); ++j) {
      s[i][j] = s[i][j - 1] + g[i][j];
    }
  }
  while (q--) {
    int a, h;
    scanf("%d %d", &a, &h);
    long long ans = query(a, h);
    while (a > 1) {
      int kid = a;
      h -= l[kid];
      if (h <= 0) {
        break;
      }
      a >>= 1; // get the parent
      ans += h;
      int x = a + a == kid ? a + a + 1 : a + a;
      if (x <= n) {
        ans += query(x, h - l[x]);
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}