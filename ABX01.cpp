// https://www.codechef.com/problems/ABX01

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int t;

ll power(ll x, ll y, ll p) {
  ll res = 1; 
  x = x % p;  
  while (y > 0) {
      if (y & 1LL)
          res = (res*x) % p;
      y = y>>1LL; 
      x = (x*x) % p;  
  }
  return res ? res : 9;
}

int main() {
  cin >> t;
  while (t--) {
    long long a, n;
    cin >> a >> n;
    printf("%lld\n", power(a, n, 9));
  }
  return 0;
}