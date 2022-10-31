// https://dmoj.ca/problem/ccc07j5

#include <bits/stdc++.h>

using namespace std;

vector <int> v = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
int dp[123];

int a, b;

int solve (int idx) {
  if (dp[idx] != -1) {
    return dp[idx];
  }
  dp[idx] = 0;
  for (int i = idx + 1; i < v.size(); ++i) {
    int d = v[i] - v[idx];
    if (a <= d && d <= b) {
      dp[idx] += solve(i);
    }
  }
  return dp[idx];
}

int main() {
  scanf("%d %d", &a, &b);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  memset(dp, -1, sizeof dp);
  dp[v.size()] = dp[v.size() - 1] = 1;
  printf("%d\n", solve(0));
  return 0;
}