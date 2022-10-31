// http://usaco.org/index.php?page=viewproblem2&cpid=596
// Nice one

#include <bits/stdc++.h>

using namespace std;

const int N = 2001;

bool ok[N][N];
bool used[N][N];
char s[N];
int dx[] = {1, -1, 0, 0, -1, 1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};
queue <pair <int, int>> q;

int n;

void bfs(int x, int y) {
  q.push({x, y});
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    used[x][y] = 1;
    for (int i = 0; i < 4; ++i) {
      int x0 = x + dx[i];
      int y0 = y + dy[i];
      if (x0 < N && y0 < N && x0 >= 0 && y0 >= 0 && !ok[x0][y0] && !used[x0][y0]) {
        q.push({x0, y0});
        used[x0][y0] = 1;
      }
    }
  } 
}

int main() {
  freopen("gates.in", "r", stdin);
  freopen("gates.out", "w", stdout);
  scanf("%d", &n);
  scanf("%s", s);
  int x = 1002, y = 1002;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'N') {
      --y;
      ok[x][y] = 1;
      --y;
      ok[x][y] = 1;
    } else if (s[i] == 'S') {
      ++y;
      ok[x][y] = 1;
      ++y;
      ok[x][y] = 1;
    } else if (s[i] == 'E') {
      ++x;
      ok[x][y] = 1;
      ++x;
      ok[x][y] = 1;
    } else {
      --x;
      ok[x][y] = 1;
      --x;
      ok[x][y] = 1;
    }
  }
  int ans = -1;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (!used[i][j] && !ok[i][j]) {
        bfs(i, j);
        ++ans;
      }
    }
  }
  printf("%d", ans);
  return 0;
}