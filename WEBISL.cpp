#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

vector <int> g[N];
bool used[N];
int ans[N];

int n;
int m;
int a;

void dfs(int x, int mark) {
  used[x] = mark;
  a = min(a, x);
  for (int to : g[x]) {
    if (!used[to]) {
      dfs(to, mark);
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  while (m--) {
    int x, y;
    scanf("%d %d", &x, &y);
    g[x].emplace_back(y);
  }
  for (int i = 0; i < n; ++i) {
    if (!used[i]) {
      a = 1 << 30;
      dfs(i, i + 1);
      ans[i + 1] = a;
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%d\n", ans[used[i]]);
  }
  return 0;
}