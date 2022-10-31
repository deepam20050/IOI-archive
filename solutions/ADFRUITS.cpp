// http://www.spoj.com/problems/ADFRUITS/

#include <bits/stdc++.h>

using namespace std;

const int N = 1234;

string a;
string b;
string ans;
char common[N];
int dp[N][N];
pair <int, int> p[N][N];

int main() {
  ios_base::sync_with_stdio(0);
  while (cin >> a >> b) {
    int n = a.size();
    int m = b.size();
    memset(common, 0, sizeof common);
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= m; ++j) {
        if (i == 0 || j == 0) {
          dp[i][j] = 0;
          p[i][j] = {-1, -1};
        } else if (a[i - 1] == b[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
          p[i][j] = {i - 1, j - 1};
        } else {
          if (dp[i - 1][j] <= dp[i][j - 1]) {
            p[i][j] = {i, j - 1};
            dp[i][j] = dp[i][j - 1];
          } else {
            p[i][j] = {i - 1, j};
            dp[i][j] = dp[i - 1][j];
          }
        }
      }
    }
    int sz = dp[n][m] - 1;
    int x = n;
    int y = m;
    while (x != -1) {
      int x0 = p[x][y].first;
      int y0 = p[x][y].second;
      if (x0 != -1 && dp[x][y] - dp[x0][y0] == 1) {
        common[sz--] = a[x - 1];
      } else if (x0 == -1) {
        break;
      }
      x = x0;
      y = y0;
    }
    int i = 0;
    int j = 0;
    ans = "";
    for (int k = 0; k < dp[n][m]; ++k, ++i, ++j) {
      while (i < n && a[i] != common[k]) {
        ans += a[i++];
      }
      while (j < m && b[j] != common[k]) {
        ans += b[j++];
      }
      ans += common[k];
    }
    while (i < n) {
      ans += a[i++];
    }
    while (j < m) {
      ans += b[j++];
    }
    cout << ans << '\n';
  }
  return 0;
}