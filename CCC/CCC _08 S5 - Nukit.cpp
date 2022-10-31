// https://dmoj.ca/problem/ccc08s5

#include <bits/stdc++.h>

using namespace std;

const int N = 31;

int dp[2][N][N][N][N];

bool solve (bool guy, int a, int b, int c, int d) {
  if (dp[guy][a][b][c][d] != -1) {
    return dp[guy][a][b][c][d];
  }
  bool temp[5];
  temp[0] = (a >= 2 && b >= 1 && d >= 2) ? solve (guy ^ 1, a - 2, b - 1, c, d - 2) : guy ^ 1;
  temp[1] = (a >= 1 && b >= 1 && c >= 1 && d >= 1) ? solve(guy ^ 1, a - 1, b - 1, c - 1, d - 1) : guy ^ 1;
  temp[2] = (c >= 2 && d >= 1) ? solve(guy ^ 1, a, b, c - 2, d - 1) : guy ^ 1;
  temp[3] = (b >= 3) ? solve(guy ^ 1, a, b - 3, c, d) : guy ^ 1;
  temp[4] = (a >= 1 && d >= 1) ? solve(guy ^ 1, a - 1, b, c, d - 1) : guy ^ 1;
  for (int i = 0; i < 5; ++i) {
    if (temp[i] == guy) {
      dp[guy][a][b][c][d] = guy;
      break;
    }
  }
  if (dp[guy][a][b][c][d] != guy) {
    dp[guy][a][b][c][d]  = guy ^ 1;
  }
  return dp[guy][a][b][c][d];
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    memset(dp, -1, sizeof dp);
    puts(!solve(0, a, b, c, d) ? "Patrick" : "Roland");
  }
  return 0;
}