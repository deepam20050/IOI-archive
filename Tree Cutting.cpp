// http://poj.org/problem?id=2378

#include <cstdio>
#include <vector>

using namespace std;

const int N = 10010;

vector <int> g[N];
bool used[N];
int c[N], p[N];

void dfs(int x) {
  used[x] = 1;
  bool ok = 1;
  for (vector<int>::iterator it = g[x].begin(); it != g[x].end(); ++it) {
    int to = *it;
    if (used[to]) {
      continue;
    }
    ok = 0;
    p[to] = x;
    dfs(to);
    c[x] += c[to] + 1;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n - 1; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1);
  for (int i = 1; i <= n; ++i) {
    bool ok = 1;
    for (vector<int>::iterator it = g[i].begin(); it != g[i].end(); ++it) {
      int to = *it;
      if (to == p[i] && ((n - c[i] - 1) << 1) > n) {
        ok = 0;
        break;
      } else if (to != p[i] && ((c[to] + 1) << 1) > n) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      printf("%d\n", i);
    }
  }
  return 0;
}