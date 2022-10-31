// https://codeforces.com/contest/437/problem/C

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector < int > v(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
  }
  int ans = 0;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    ans += min(v[x], v[y]);
  }
  cout << ans;
  return 0;
}