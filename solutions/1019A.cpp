// http://codeforces.com/contest/1019/problem/A

#include <bits/stdc++.h>

using namespace std;

const int N = 3e3 + 5;

vector < int > v[N];
vector < pair < int, pair < int, int > > > pi;

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    int p, c;
    cin >> p >> c;
    if (p == 1) {
      c = 0;
    }
    v[p].emplace_back(c);
  }
  for (int i = 1; i <= m; ++i) {
    sort(v[i].rbegin(), v[i].rend());
    for (int j = 0; j < v[i].size(); ++j) {
      pi.push_back({v[i][j], {i, j}});
    }
  }
  sort(pi.begin(), pi.end());
  long long ans = 1e18;
  for (int i = 1; i <= n; ++i) {
    int cnt = 0;
    long long curr = 0;
    for (int j = 1; j <= m; ++j) {
      for (int k = i - 1; k < v[j].size(); ++k) {
        ++cnt;
        curr += v[j][k];
      }
    }
    for (const auto &e : pi) {
      if (cnt < i && e.second.second < i - 1) {
        ++cnt;
        curr += e.first;
      }
    }
    ans = min(ans, curr);
  }
  cout << ans;
  return 0;
}