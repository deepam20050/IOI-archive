// http://www.spoj.com/problems/SOLDIER/

#include <bits/stdc++.h>

using namespace std;

const int N = 10000;

vector < pair <int, int> > v[6];
bool yes[6];
int dp[6][N];

int main() {
  int n, t;
  scanf("%d %d", &n, &t);
  for (int i = 0; i < n; ++i) {
    int type;
    scanf("%d", &type);
    --type;
    int x, y;
    scanf("%d %d", &x, &y);
    v[type].push_back({x, y});
    yes[type] = 1;
  }
  if (accumulate(yes, yes + 6, 0) != 6) {
    printf("0\n");
    return 0;
  }
  for (auto &e : v[5]) {
    int p = e.first, q = e.second;
    for (int i = p; i <= t; ++i) {
      dp[5][i] = max(dp[5][i], q);
    }
  }
  for (int i = 4; i >= 0; --i) {
    for (auto &e : v[i]) {
      int p = e.first, q = e.second;
      for (int j = p; j <= t; ++j) {
        if (dp[i + 1][j - p]) {
          dp[i][j] = max(dp[i][j], min(dp[i + 1][j - p], q));
        }
      }
    }
  }
  printf("%d\n", *max_element(dp[0], dp[0] + N));
  return 0;
}