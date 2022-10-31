ll power (ll x, ll y) {
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