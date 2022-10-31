// http://codeforces.com/contest/25/problem/E

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pi = pair < long long, long long >;

const int N = 1e5 + 5;
const long long p1 = 31;
const long long p2 = 41;
const long long mod1 = 1e9 + 7;
const long long mod2 = 1e9 + 9;

long long power1[N];
long long power2[N];
long long prefix1[3][N];
long long prefix2[3][N];
pi suff[3][N];
string s[3];
int arr[3] = {0, 1, 2};
bool yes[3][3];

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

ll inv (ll x, ll mod) { return mod_exp(x, mod - 2, mod); }
ll add (ll a, ll b, ll mod) { return (a + b) % mod; }
ll mul (ll a, ll b, ll mod) { return (a * b) % mod; }
ll sub (ll a, ll b, ll mod) { return (a - b + mod) % mod; }

pi see (int l, int r, int idx) {
  pi p;
  if (l > 0) {
    p.first = mul(sub(prefix1[idx][r], prefix1[idx][l - 1], mod1), inv(power1[l], mod1), mod1);
    p.second = mul(sub(prefix2[idx][r], prefix2[idx][l - 1], mod2), inv(power2[l], mod2), mod2);
  } else {
    p.first = prefix1[idx][r];
    p.second = prefix2[idx][r];
  }
  return p;
}

inline void compute (string &str, int idx) {
  prefix1[idx][0] = str[0];
  prefix2[idx][0] = str[0];
  int n = str.size();
  for (int i = 1; i < n; ++i) {
    prefix1[idx][i] = add(prefix1[idx][i - 1], mul(str[i], power1[i], mod1), mod1);
    prefix2[idx][i] = add(prefix2[idx][i - 1], mul(str[i], power2[i], mod2), mod2);
  }
  for (int i = n - 1; i >= 0; --i) {
    suff[idx][i] = see(i, n - 1, idx);
  }
  sort(suff[idx], suff[idx] + n);
}

bool check (int idx1, int idx2) {
	if (s[idx2].size() < s[idx1].size()) {
		return 0;
	}
	int i = 0;
	int j = s[idx1].size() - 1;
	int k = s[idx1].size() - 1;
	while (j < s[idx2].size()) {
		if (see(i, j, idx2) == pi(prefix1[idx1][k], prefix2[idx1][k])) {
			return 1;
		}
		++i;
		++j;
	}
	return 0;
}

inline int solve () {
  int ret = s[arr[0]].size();
  for (int i = 1; i < 3; ++i) {
  	if (yes[arr[i]][arr[i - 1]]) {
  		continue;
  	}
  	if (i == 2 && yes[arr[i]][arr[i - 2]]) {
  		break;
  	}
    int sub = 0;
    for (int j = s[arr[i]].size() - 1; j >= 0; --j) {
      if (binary_search(suff[arr[i - 1]], suff[arr[i - 1]] + s[arr[i - 1]].size(), pi(prefix1[arr[i]][j], prefix2[arr[i]][j]))) {
        sub = j + 1; 
        break;
      }
    }
    ret += s[arr[i]].size() - sub;
  }
  return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	power1[0] = 1;
  power2[0] = 1;
  for (int i = 1; i < N; ++i) {
    power1[i] = mul(power1[i - 1], p1, mod1);
    power2[i] = mul(power2[i - 1], p2, mod2);
  }
	for (int i = 0; i < 3; ++i) {
		cin >> s[i];
		compute(s[i], i);
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i == j) {
				continue;
			}
			yes[i][j] = check(i, j);
		}
	}
	int res = 1 << 29;
	do {
		res = min(res, solve());
	} while (next_permutation(arr, arr + 3));
	cout << res << '\n';
	return 0;
}