// http://poj.org/problem?id=2385

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <cctype>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <vector>
#include <utility>

using namespace std;

const int N = 1010, T = 40;

int dp[2][N][T], a[N];

int n, w;

int solve(int who, int idx, int left) {
  if (left < 0 || idx >= n) {
    return 0;
  }
  if (dp[who][idx][left] != -1) {
    return dp[who][idx][left];
  }
  return dp[who][idx][left] = max(solve(who, idx + 1, left) + (a[idx] == who), solve(who ^ 1, idx, left - 1) + (a[idx] == who));
}

int main() {
  scanf("%d %d", &n, &w);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    if (a[i] == 2) {
      a[i] = 0;
    }
  }
  memset(dp, -1, sizeof dp);
  printf("%d", solve(1, 0, w));
  return 0;
}