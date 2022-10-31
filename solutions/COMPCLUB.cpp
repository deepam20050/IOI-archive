// https://www.codechef.com/problems/COMPCLUB

#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 1;
const int mod = 1e9 + 7;

vector < int > g[N];
vector < int > dp[N];
int ans[N];
int level[N];
int club[N];
int cnt[N];

void dfs (int x) {
  int tmp = level[x] && level[x] < cnt[club[x]] ? dp[club[x]][level[x] - 1] : 0;  
  for (int to : g[x]) {
    dfs(to);
  }
  if (level[x] >= cnt[club[x]]) {
    return;
  }  
  if (!level[x]) {
    ans[x] = 1;
  } else  {
    ans[x] = (dp[club[x]][level[x] - 1] - tmp + mod) % mod;
  }
  dp[club[x]][level[x]] += ans[x];
  dp[club[x]][level[x]] %= mod;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n, x;
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; ++i) {
      g[i].clear();
      dp[i].clear();
      cnt[i] = 0;
      ans[i] = 0;
    }
    for (int i = 1, p; i < n; ++i) {
      scanf("%d", &p);
      g[p].emplace_back(i);
    }
    for (int i = 0; i < n; ++i) {
      scanf("%d", club + i);
      ++cnt[club[i]];
    }
    for (int i = 0; i < n; ++i) {
      scanf("%d", level + i);
      dp[i] = vector < int > (cnt[i]);
    }
    dfs(0);
    for (int i = 0; i < n; ++i) {
      printf("%d\n", ans[i]);
    }
  }
  return 0;
}