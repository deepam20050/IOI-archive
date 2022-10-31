// https://www.codechef.com/problems/ISTA2002

#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

const int N = 100010;

long long x[N], y[N], z[N];

int n;
long long l, b, h;

long long solve(long long v[]) {
  long long ans = -1LL;
  for (int i = 1; i <= n + 1; ++i) {
    ans = max(ans, v[i] - v[i - 1]);
  }
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    x[0] = y[0] = z[0] = 0;
    scanf("%d %lld %lld %lld", &n, &l, &b, &h);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld %lld %lld", x + i, y + i, z + i);
    }
    x[n + 1] = l;
    y[n + 1] = b;
    z[n + 1] = h;
    sort(x, x + n + 2);
    sort(y, y + n + 2);
    sort(z, z + n + 2);
    long long xmax = solve(x), ymax = solve(y), zmax = solve(z);
    printf("%lld\n", (((xmax * ymax) % mod) * zmax) % mod);
  }
  return 0;
}