// https://csacademy.com/contest/round-58/task/palindromic-friendship/statement/

#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

vector <int> e[N];
int dp[2][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (x > y) {
      swap(x, y);
    }
    e[y - x + 1].emplace_back(x);
  }
  fill(dp[1], dp[1] + n + 1, 1);
  for (int len = 2; len <= n; ++len) {
    sort(e[len].begin(), e[len].end());
    for (int x : e[len]) {
      if (dp[len & 1][x + 1] == len - 2) {
        dp[len & 1][x] = len;
      }
    }
  }
  int ans = 1;
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, max(dp[0][i], dp[1][i]));
  }
  printf("%d\n", ans);
  return 0;
}