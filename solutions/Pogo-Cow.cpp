// http://www.usaco.org/index.php?page=viewproblem2&cpid=345
// Nice DP

#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int best[N][N];
int dp[N][N];
int dist[N][N];
pair <int, int> p[N];

int n;

int abso(int x) {
  return x < 0 ? -x : x;
}

int solve() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      dist[i][j] = abso(p[j].first - p[i].first);
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    for (int j = i + 1; j < n; ++j) {
      int d = dist[i][j];
      dp[i][j] = p[i].second;
      if (dist[j][n - 1] < d) {
        dp[i][j] += p[j].second;
        continue;
      }
      int idx = lower_bound(dist[j] + j, dist[j] + n, d) - dist[j];
      dp[i][j] += best[j][idx];
    }
    for (int j = n - 1; j > i; --j) {
      best[i][j] = max(best[i][j + 1], dp[i][j]);
    }
  }
  int ans = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ans = max(ans, best[i][j]);
    }
  }
  return ans;
}

int main() {
  freopen("pogocow.in", "r", stdin);
  freopen("pogocow.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &p[i].first, &p[i].second);
  }
  sort(p, p + n);
  int ans = solve();
  reverse(p, p + n);
  ans = max(ans, solve());
  printf("%d\n", ans);
  return 0;
}