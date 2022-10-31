// http://www.spoj.com/problems/ACMAKER/

#include <bits/stdc++.h>

using namespace std;

const int N = 200;

string w[N];
vector <string> v;
int dp[N][N][N];

int get(int idx, int pos, int loc) {
  int ret = 0;
  if (loc >= v[0].size() || idx >= v.size()) {
    return 0;
  }
  while (pos < v[idx].size()) {
    if (toupper(v[idx][pos]) == v[0][loc]) {
      ret += dp[idx][pos][loc];
    }
    ++pos;
  }
  return ret;
}

int main() {
  int _;
  while (scanf("%d", &_) && _) {
    for (int i = 0; i < _; ++i) {
      cin >> w[i];
    }
    getchar();
    sort(w, w + _);
    string in;
    while (getline(cin, in) && in != "LAST CASE") {
      istringstream iss(in);
      string t;
      v.clear();
      memset(dp, 0, sizeof dp);
      while (iss >> t) {
        if (!binary_search(w, w + _, t)) {
          v.emplace_back(t);
        }
      }
      const int n = v.size();
      for (int i = 0; i < v[n - 1].size(); ++i) {
        if (toupper(v[n - 1][i]) == v[0].back()) {
          dp[n - 1][i][v[0].size() - 1] = 1;
        }
      }
      for (int pos = v[0].size() - 2; pos >= 0; --pos) {
        for (int i = 1; i < n; ++i) {
          for (int j = 0; j < v[i].size(); ++j) {
            if (toupper(v[i][j]) == v[0][pos]) {
              dp[i][j][pos] += get(i, j + 1, pos + 1);
              dp[i][j][pos] += get(i + 1, 0, pos + 1);
            }
          }
        }
      }
      int ans = 0;
      for (int j = 0; j < v[1].size(); ++j) {
        ans += dp[1][j][0];
      }
      if (ans) {
        cout << v[0] << " can be formed in " << ans << " ways\n";
      } else {
        cout << v[0] << " is not a valid abbreviation\n";
      }
    }
  }
  return 0;
}