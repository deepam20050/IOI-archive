// http://www.spoj.com/problems/BITMAP/

#include <bits/stdc++.h>

using namespace std;

const int N = 200;
const int oo = 1 << 30;

char s[N][N];
int d[N][N];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
queue <pair <int, int>> q;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
      scanf("%s", s[i]);
      fill(d[i], d[i] + m, oo);
      for (int j = 0; j < m; ++j) {
        if (s[i][j] == '1') {
          d[i][j] = 0;
          q.push({i, j});
        }
      }
    }
    while (!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      for (int i = 0; i < 4; ++i) {
        int x0 = x + dx[i];
        int y0 = y + dy[i];
        if (0 <= x0 && x0 < n && 0 <= y0 && y0 < m && d[x0][y0] > d[x][y] + 1) {
          d[x0][y0] = d[x][y] + 1;
          q.push({x0, y0});
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        printf("%d ", d[i][j]);
      }
      puts("");
    }
  }
  return 0;
}