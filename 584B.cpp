// http://codeforces.com/contest/584/problem/B

#include <bits/stdc++.h>

using namespace std;

const int N = 300010;
const long long mod = 1e9 + 7;

long long three[N];
long long seven[N];

long long m(long long x) {
  return (x % mod + mod) % mod;
}

int main() {
  int n;
  scanf("%d", &n);
  three[0] = seven[0] = 1;
  for (int i = 1; i <= n + n + n; ++i) {
    three[i] = three[i - 1] * 3;
    three[i] %= mod;
    if (i <= n) {
      seven[i] = seven[i - 1] * 7;
      seven[i] %= mod;
    }
  }
  printf("%lld", m(three[n + n + n] - seven[n]));
  return 0;
}