#include <bits/stdc++.h>

using namespace std;

const int N = 122;
const int oo = 1 << 30;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int dist[N][N];
char s[N][N];
char ori[N][N];
deque < pair < int, int > > dq;
pair < int, int > p[N][N];
pair < int, int > who[2];
int tc;
int n;
int m;

inline void restore () {
  for (int i = 0; i < n; ++i) {
    fill(dist[i], dist[i] + m, oo);
  }
  while (!dq.empty()) {
    dq.pop_front();
  }
}

inline int calc () {
  int ret = oo;
  for (int i = 0; i < n; ++i) {
    ret = min(ret, min(dist[i][0], dist[i][m - 1]));
  }
  for (int i = 0; i < m; ++i) {
    ret = min(ret, min(dist[0][i], dist[n - 1][i]));
  }
  return ret;
}

int bfs2 (int idx, int weight) {
  restore();
  int x = who[idx].first;
  int y = who[idx].second;
  while (x && y) {
    if (ori[x][y] == '#') {
      s[x][y] = '.';
    }
    int tmpx = p[x][y].first;
    int tmpy = p[x][y].second;
    x = tmpx;
    y = tmpy;
  }
  x = who[idx].first;
  y = who[idx].second;
  dq.push_back({x, y});
  cout << weight << '\n';
  dist[x][y] = weight;
  while (!dq.empty()) {
    int x = dq.front().first, y = dq.front().second;
    dq.pop_front();
    for (int i = 0; i < 4; ++i) {
      int x0 = dx[i] + x, y0 = dy[i] + y;
      if (0 <= x0 && x0 < n && 0 <= y0 && y0 < m && s[x0][y0] != '*') {
        bool d = (s[x0][y0] == '#');
        if (dist[x0][y0] > dist[x][y] + d) {
          dist[x0][y0] = dist[x][y] + d;
          if (d) {
            dq.push_back({x0, y0});
          } else {
            dq.push_front({x0, y0});
          }
        }
      }
    }
  }
  return calc();
}

pair < int, bool > bfs (int idx) {
  int x = who[idx].first;
  int y = who[idx].second;
  restore();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      s[i][j] = ori[i][j];
    }
  }
  dq.push_back({x, y});
  dist[x][y] = 0;
  p[x][y] = {0, 0};
  while (!dq.empty()) {
    int x = dq.front().first, y = dq.front().second;
    if (dq.front() == who[idx ^ 1]) {
      return make_pair(bfs2(idx ^ 1, dist[x][y]), 1);
    }
    dq.pop_front();
    for (int i = 0; i < 4; ++i) {
      int x0 = dx[i] + x, y0 = dy[i] + y;
      if (0 <= x0 && x0 < n && 0 <= y0 && y0 < m && ori[x0][y0] != '*') {
        bool d = (ori[x0][y0] == '#');
        if (dist[x0][y0] > dist[x][y] + d) {
          dist[x0][y0] = dist[x][y] + d;
          p[x0][y0] = {x, y};
          if (d) {
            dq.push_back({x0, y0});
          } else {
            dq.push_front({x0, y0});
          }
        }
      }
    }
  }
  return make_pair(calc(), 0);
}

int main() {
  scanf("%d", &tc);
  while (tc--) {
    scanf("%d %d", &n, &m);
    int whose = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%s", ori[i]);
      for (int j = 0; j < m; ++j) {
        if (ori[i][j] == '$') {
          who[whose++] = {i, j};
        }
      }
    }
    int res = oo;
    int arr[] = {1 << 29, 1 << 29};
    for (int i = 0; i < 2; ++i) {
      auto pp = bfs(i);
      if (pp.second) {
        res = min(res, pp.first);
      } else {
        arr[i] = pp.first;
      }
    }
    printf("%d\n", min(res, arr[0] + arr[1]));
  }
  return 0;
}