#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 1;
const ll MOD = 1e9 + 9;

ll power (ll x, ll y, ll mod = MOD) {
  ll res = 1;
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

ll inv (ll x, ll mod = MOD) { return power(x, mod - 2); }
ll mul (ll a, ll b, ll mod = MOD) { return a * b % mod; }
ll di (ll a, ll b, ll mod = MOD) { return a * inv(b, mod); }
ll sub (ll a, ll b, ll mod = MOD) { return (a - b + mod) % mod; }
ll add (ll a, ll b, ll mod = MOD) { return (a + b) % mod; }

int main() {
  scanf("%d %d %d %d %d", &n, &a, &b, &k, s);
  for (int i = 0; i < k; ++i) {
    int mull = s[i] == '+' ? 1 : -1;
    ll tmp = mul(power(a, ))
  }
  return 0;
}