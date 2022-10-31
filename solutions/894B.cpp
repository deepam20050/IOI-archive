// Perfect explanation - http://codeforces.com/blog/entry/55884?#comment-396398
// http://codeforces.com/problemset/problem/894/B

#include <bits/stdc++.h>

using namespace std;

const long long mod = 1000000007;

long long power (long long x, long long y) {
  long long res = 1;
  x = x % mod;
  while (y > 0) {
    if (y & 1LL) {
        res = (res * x) % mod;
    }
    y = y >> 1LL; 
    x = (x * x) % mod;  
  }
  return res;
}

int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  if (k == -1 && n % 2 != m % 2) {
    puts("0");
    return 0;
  }
  printf("%lld\n", power(power(2, n - 1), m - 1));
  return 0;
}