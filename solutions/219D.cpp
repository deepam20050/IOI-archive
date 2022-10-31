// http://codeforces.com/problemset/problem/219/D

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;

vector < int > g[N];
pair < int, int > arr[N];
int dp1[N];
int ans[N];
int n;

bool yes (int x, int y) {
  return binary_search(arr, arr + n - 1, make_pair(x, y)); 
}

void dfs1 (int x, int p) {
  for (int to : g[x]) {
    if (to != p) {
      dfs1(to, x);
    }
  }
  for (int to : g[x]) {
    if (to == p) {
      continue;
    }
    dp1[x] += yes(to, x) + dp1[to];
  }
}

void dfs2 (int x, int p, int sum = 0) {
  ans[x] = dp1[x] + sum;
  sum += dp1[x];
  for (int to : g[x]) {
    if (to == p) {
      continue;
    }
    sum -= dp1[to];
    sum -= yes(to, x);
    sum += yes(x, to);
    dfs2(to, x, sum);
    sum += dp1[to];
    sum += yes(to, x);
    sum -= yes(x, to);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0, x, y; i < n - 1; ++i) {
    scanf("%d %d", &x, &y);
    arr[i] = {x, y};
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }
  sort(arr, arr + n - 1);
  dfs1(1, -1);
  dfs2(1, -1);
  int mini = 1 << 30;
  for (int i = 1; i <= n; ++i) {
    mini = min(mini, ans[i]);
  }
  printf("%d\n", mini);
  for (int i = 1; i <= n; ++i) {
    if (mini == ans[i]) {
      printf("%d ", i);
    }
  }
  return 0;
}