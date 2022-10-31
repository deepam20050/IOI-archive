// http://codeforces.com/problemset/problem/909/C

#include <bits/stdc++.h>

using namespace std;

const int N = 5010;
const int mod = 1e9 + 7;

bool a[N];
int dp[N][N];
int sum[N][N];

int n;

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    char ch;
    cin >> ch;
    a[i] = (ch == 'f');
  }
  for (int i = 1; i < N; ++i) {
    dp[n - 1][i] = 1;
    sum[n - 1][i] = sum[n - 1][i - 1] + 1;
  }
  for (int i = n - 2; i >= 0; --i) {
    for (int j = 1; j < N; ++j) {
      if (a[i]) {
        dp[i][j] += dp[i + 1][j + 1];
      } else {
        dp[i][j] += sum[i + 1][j];
      }
      dp[i][j] %= mod;
      sum[i][j] += dp[i][j];
      sum[i][j] %= mod;
      sum[i][j] += sum[i][j - 1];
      sum[i][j] %= mod;
    }
  }
  cout << dp[0][1];
  return 0;
}