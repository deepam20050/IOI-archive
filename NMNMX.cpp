// https://www.codechef.com/JULY18A/problems/NMNMX

#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5;
const long long MOD1 = 1E9 + 6;
const long long MOD2 = 1E9 + 7;

long long arr[N];
long long pascal[N][N];
int tc;
int n;
int k;

inline void calc_pascal (const long long &mod, const int &SZ) {
  for (int i = 0; i < SZ; ++i){
    pascal[i][0] = 1LL;
    for (int j = 1; j <= i; ++j){
      pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
      pascal[i][j] -= (pascal[i][j] >= mod) * mod; 
    }
  }
}

inline long long power (long long x, long long y, long long mod) {
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
  calc_pascal(MOD1, N);
  scanf("%d", &tc);
  while (tc--) {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", arr + i);
    }
    sort(arr + 1, arr + n + 1);
    long long prod = 1LL;
    for (int x = 2; x < n; ++x) {
      long long s = 0LL;
      for (int m = 1; m <= k - 2; ++m) {
        s += pascal[x - 1][m] * pascal[n - x][k - m - 1] % MOD1;
        s %= MOD1;
      }
      prod *= power(arr[x], s, MOD2);
      prod %= MOD2;
    }
    printf("%lld\n", prod);
  }
  return 0;
}