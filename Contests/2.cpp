#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int g[N];
int used[N];

int dfs (int x) {
  ++used[x];
  if (used[x] == 2) {
    return x;
  }
  return dfs(g[x]);
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> g[i];
  }
  for (int i = 1; i <= n; ++i) {
    memset(used, 0, sizeof used);
    cout << dfs(i) << " ";
  }
  return 0;
}