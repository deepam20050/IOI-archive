#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const long long mod = 1e9 + 7;

long long arr[N];
long long pro[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", arr + i);
    pro[i] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; j += i) {
      pro[i] *= arr[j];
      pro[i] %= mod;
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int tt;
    scanf("%d", &tt);
    if (tt == 1) {
      int x;
      long long y;
      scanf("%d %lld", &x, &y);
      int val = x - 1;
      for (int i = 1; i * i <= val; ++i) {
        if (val % i == 0) {
          pro[i] /= arr[x];
          pro[i] *= y;
          pro[i] %= mod;
          int div = val / i;
          pro[div] /= arr[x];
          pro[div] *= y;
          pro[div] %= mod;
        }
      }
      for (int i = 1; i <= n; i += x) {
        pro[i] /= arr[x];
        pro[i] *= y;
        pro[i] %= mod;
      }
      arr[x] = y;
    } else {
      int x;
      scanf("%d", &x);
      long long val = pro[x];
      while (val >= 10) {
        val /= 10;
      }
      printf("%lld %lld\n", val, pro[x]);
    }
  }
  return 0;
}