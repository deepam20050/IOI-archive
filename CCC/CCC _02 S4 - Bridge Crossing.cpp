// https://dmoj.ca/problem/ccc02s4

#include <bits/stdc++.h>

using namespace std;

const int N = 123;

int dp[N];
int a[N];
int front[N];
char s[N][N];

int m, n;

int solve (int idx) {
  if (dp[idx] != -1) {
    return dp[idx];
  }
  int mx = -1;
  dp[idx] = 1 << 30;
  for (int i = 0; i < m && i + idx < n; ++i) {
    mx = max(mx, a[i + idx]);
    int rem = solve(idx + i + 1); 
    if (dp[idx] > mx + rem) {
      front[idx] = idx + i + 1;
      dp[idx] = mx + rem;
    }
  }
  return dp[idx];
}

int main() {
  scanf("%d %d", &m, &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
    scanf("%d", a + i);
  }
  memset(dp, -1, sizeof dp);
  dp[n] = 0;
  printf("Total Time: %d\n", solve(0));
  int curr = 0;
  while (curr != n) {
    int after = front[curr];
    while (curr != after) {
      printf("%s ", s[curr]);
      ++curr;
    }
    puts("");
  }
  return 0;
}