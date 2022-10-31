// http://www.spoj.com/problems/KOICOST/

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const long long mod = 1e9;

long long size[N], sum[N];
int p[N];
pair <int, pair <int, int>> e[N];

int find_set(int x) {
  return p[x] == x ? x : (p[x] = find_set(p[x]));
}

void join(int x, int y) {
  int a = find_set(x), b = find_set(y);
  if (size[a] < size[b]) {
    swap(a, b);
  }
  p[b] = a;
  size[a] += size[b];
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int a, b, w;
    scanf("%d %d %d", &a, &b, &w);
    e[i] = {w, {a, b}};
  }
  sort(e, e + m);
  for (int i = 1; i <= n; ++i) {
    size[i] = 1;
    p[i] = i;
  }
  sum[0] = e[0].first;
  for (int i = 1; i < m; ++i) {
    sum[i] += sum[i - 1] + e[i].first;
  }
  long long ans = 0;
  for (int i = m - 1; i >= 0; --i) {
    int a = e[i].second.first, b = e[i].second.second, w = e[i].first;
    int x = find_set(a), y = find_set(b);
    if (x != y) {
      ans += (long long)size[x] * size[y] * sum[i];
      ans %= mod;
      join(x, y);
    }
  }
  printf("%lld\n", ans);
  return 0;
}