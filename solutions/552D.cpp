// http://codeforces.com/contest/552/problem/D

#include <bits/stdc++.h>

using namespace std;

const int N = 2001;

unordered_map <double, long long> mp[N];
vector <double> g[N];
int x[N];
int y[N];

inline long long cnt (long long x) {
  return x * (x - 1) >> 1;
}

int main() {
  long long n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  if (n < 3) {
    puts("0");
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      double m = 500;
      if (x[j] != x[i]) {
        m = double(y[i] - y[j]) / double(x[j] - x[i]);
      }
      g[i].emplace_back(m);
      ++mp[i][m];
    }
  }
  long long ans = (long long)(n * (n - 1) * (n - 2)) / 6;
  for (int i = 0; i < n; ++i) {
    for (double m : g[i]) {
      ans -= cnt(mp[i][m]);
      mp[i][m] = 0;
    }
  }
  printf("%lld\n", ans);
  return 0;
}