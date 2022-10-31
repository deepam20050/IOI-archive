// https://www.codechef.com/problems/SNSOCIAL
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 501;

int n, m;

int a[N][N];
bool used[N][N];

int dx[] = {1, 1, 1, -1, -1, -1, 0, 0}, dy[] = {1, 0, -1, 1, 0, -1, 1, -1};

bool valid(int x, int y) {
  if (x >= 1 && x <= n && y >= 1 & y <= m) {
    return 1;
  }
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int mx = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        scanf("%d", &a[i][j]);
        mx = max(mx, a[i][j]);
        used[i][j] = 0;
      }
    }
    queue < pair < pair < int, int >, int > > q;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (a[i][j] == mx) {
          q.push({{i, j}, 0});
          used[i][j] = 1;
        }
      }
    }
    int ans = -1;
    while (!q.empty()) {
      auto top = q.front(); 
      q.pop();
      int x = top.first.first, y = top.first.second, d = top.second;
      ans = max(ans, d); 
      for (int i = 0; i < 8; ++i) {
        int x0 = x + dx[i], y0 = y + dy[i];
        if (valid(x0, y0) && !used[x0][y0]) {
          q.push({{x0, y0}, d + 1});
          used[x0][y0] = 1;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}

