// http://www.spoj.com/problems/ADACLEAN/

#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const long long p1 = 31;
const long long p2 = 41;
const long long mod1 = 1e9 + 7;
const long long mod2 = 1e9 + 9;

long long power1[N];
long long power2[N];
long long prefix1[N];
long long prefix2[N];
char s[N];
set < pair < long long, long long > > st;

int n;
int k;

long long mod_exp (long long x, long long y, long long mod) {
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

long long inv (long long x, long long mod) {
	return mod_exp(x, mod - 2, mod);
}

long long mod_sub(long long a, long long b, long long mod){
   return (a - b + mod) % mod;
}

long long mod_add(long long a, long long b, long long mod){
    return (a + b) % mod;
}

long long mod_mul(long long a, long long b, long long mod){
    return (a * b) % mod;
}


inline void init () {
	power1[0] = 1;
	power2[0] = 1;
	for (int i = 1; i < N; ++i) {
		power1[i] = mod_mul(power1[i - 1], p1, mod1);
		power2[i] = mod_mul(power2[i - 1], p2, mod2);
	}
}

inline void compute () {
	prefix1[0] = s[0];
	prefix2[0] = s[0];
	for (int i = 1; i < n; ++i) {
		prefix1[i] = mod_add(prefix1[i - 1], mod_mul(s[i], power1[i], mod1), mod1);
		prefix2[i] = mod_add(prefix2[i - 1], mod_mul(s[i], power2[i], mod2), mod2);
	}
}

pair < long long, long long > see (int l, int r) {
	pair < long long, long long > p;
	if (l > 0) {
		p.first = mod_mul(mod_sub(prefix1[r], prefix1[l - 1], mod1), inv(power1[l], mod1), mod1);
		p.second = mod_mul(mod_sub(prefix2[r], prefix2[l - 1], mod2), inv(power2[l], mod2), mod2);
	} else {
		p.first = prefix1[r];
		p.second = prefix2[r];
	}
	return p;
}

int main() {
	init();
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &n, &k);
		scanf("%s", s);
		compute();
		st.clear();
		int l = 0;
		int r = k - 1;
		while (r < n) {
			auto p = see(l, r);
			st.insert(p);
			++l;
			++r;
		}
		printf("%d\n", (int)st.size());
	}
	return 0;
}