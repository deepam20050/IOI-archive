// http://codeforces.com/problemset/problem/60/B

#include <bits/stdc++.h>

using namespace std;

const int N = 22;

int dx[] = {0, 0, 0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0, 0, 0};
int dz[] = {0, 0, 1, -1, 0, 0};;
char s[N][N][N];
queue < pair <int, pair <int, int> > > q;

int k, n, m, ans;

int main() {
  scanf("%d %d %d", &k, &n, &m);
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%s", s[i][j]);
    }
  }
  int px, py;
  scanf("%d %d", &px, &py);
  q.push({px - 1, {py - 1, 0}});
  while (!q.empty()) {
    int x = q.front().first, y = q.front().second.first, z = q.front().second.second;
    s[z][x][y] = '#';
    q.pop();
    ++ans;
    for (int i = 0; i < 6; ++i) {
      int a = x + dx[i];
      int b = y + dy[i];
      int c = z + dz[i];
      if ((0 <= a && a < n) && (0 <= b && b < m) && (0 <= c && c < k) && (s[c][a][b] == '.')) {
        s[c][a][b] = '#';
        q.push({a, {b, c}});
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}