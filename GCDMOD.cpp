// https://www.codechef.com/AUG18B/problems/GCDMOD

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const long long MOD = 1e9 + 7;

inline long long power (long long x, long long y, long long mod = MOD) {
  long long res = 1;
  x %= mod;
  while (y > 0) {
    if (y & 1LL) {
      res = (res * x) % mod;
    }
    y >>= 1LL; 
    x = (x * x) % mod;  
  }
  return res;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    long long a, b, n;
    scanf("%lld %lld %lld", &a, &b, &n);
    long long d = a - b;
    if (d == 0) {
      printf("%lld\n", (power(a, n) + power(b, n)) % MOD);
      continue;
    }
    long long ans = 1;
    for (long long i = N; i >= 1; --i) {
      if (d % i) {
        continue;
      }
      long long x = i;
      long long y = d / i;
      if ((power(a, n, x) + power(b, n, x)) % x == 0) {
        ans = max(ans, x);
      }
      if ((power(a, n, y) + power(b, n, y)) % y == 0) {
        ans = max(ans, y);
      }
    }
    printf("%lld\n", ans % MOD);
  }
  return 0;
}