// http://codeforces.com/contest/742/problem/D

#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

vector <int> g[N];
vector <int> a[N];
bool used[N];
int b[N];
int w[N];
int dp[N];
int t[N];

void dfs(int x, int curr) {
  used[x] = 1;
  a[curr].emplace_back(x);
  for (int j : g[x]) {
    if (!used[j]) {
      dfs(j, curr);
    }
  }
}

int main() {
  int n, m, weight;
  scanf("%d %d %d", &n, &m, &weight);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", w + i);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", b + i);
  }
  while (m--) {
    int x, y;
    scanf("%d %d", &x, &y);
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }
  int curr = 0;
  for (int i = 1; i <= n; ++i) {
    if (!used[i]) {
      dfs(i, curr++);
    }
  }
  for (int i = 0; i < curr; ++i) {
    for (int j = 0; j <= weight; ++j) {
      t[j] = dp[j];
    }
    int bb = 0;
    int ww = 0;
    for (int x : a[i]) {
      bb += b[x];
      ww += w[x];
    }
    for (int x : a[i]) {
      for (int j = 1; j <= weight; ++j) {
        if (w[x] <= j) {
          dp[j] = max(dp[j], t[j - w[x]] + b[x]);
        }
        if (ww <= j) {
          dp[j] = max(dp[j], t[j - ww] + bb);
        }
      }
    }
  }
  printf("%d", dp[weight]);
  return 0;
}