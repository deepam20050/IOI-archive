#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

long long arr[N];
long long x[N];
long long y[N];
long long z[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%lld %lld %lld", x + i, y + i, z + i);
  }
  long long ans = 0;
  for (int mask = 0; mask < 8; ++mask) {
    int a = mask & 1 ? 1 : -1;
    int b = mask & 2 ? 1 : -1;
    int c = mask & 4 ? 1 : -1;
    for (int i = 0; i < n; ++i) {
      arr[i] = a * x[i] + b * y[i] + c * z[i];
    }
    sort(arr, arr + n, greater < long long > ());
    long long ret = 0;
    for (int i = 0; i < m; ++i) {
      ret += arr[i];
    }
    ans = max(ans, ret);
  }
  printf("%lld\n", ans);
  return 0;
}