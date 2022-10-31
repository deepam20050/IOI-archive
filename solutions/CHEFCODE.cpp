// https://www.codechef.com/MAY17/problems/CHEFCODE
// AC
// Meet in the middle + the excellent boost libraries solved the problem!

#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = boost::multiprecision::cpp_int;

const int N = 50000;

ll k;

ll x[N], y[N], a[40];

void calc(ll v[], int n, int c) {
  for (int i = 0; i < (1 << n); ++i) {
    v[i] = 0;
    bool f = 1;
    for (int j = 0; j < n; ++j) {
      if (v[i] > k) {
        v[i] = 0;
        break;
      }
      if (i & (1 << j)) {
        if (f) {
          v[i] = a[j + c];
          f = 0;
        } else {
          v[i] *= a[j + c];
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i]; 
  }
  calc(x, n/2, 0);
  calc(y, n - n/2, n/2);
  int sz1 = 1 << n/2;
  int sz2 = 1 << (n - n/2);
  sort(x, x + sz1, greater <ll> ());
  sort(y, y + sz2);
  int lim1 = -1, st = -1;
  long ans = 0;
  for (int i = 0; i < sz1; ++i) {
    if (lim1 == -1 && x[i] == 0) {
      lim1 = i;
      break;
    }
    if (x[i] <= k) {
      ++ans;
    }
  }
  for (int i = 0; i < sz2; ++i) {
    if (st == -1 && y[i] > 0) {
      st = i;
      break;
    }
  }
  for (int i = 0; i < sz2; ++i) {
    if (y[i] <= k && y[i] > 0) {
      ++ans;
    }
  }
  // cout << ans << '\n';
  int j = st, cnt = 0;
  for (int i = 0; i < lim1; ++i) {
    while (j < sz2 && x[i] <= k && y[j] <= k && x[i] * y[j] <= k) {
      ++j;
      ++cnt;
    }
    ans += cnt;
  }
  cout << ans << '\n';
  return 0;
}
