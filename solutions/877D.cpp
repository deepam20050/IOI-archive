#include <bits/stdc++.h>

using namespace std;

const int N = 1234, oo = 1 << 30;

int dx[4], dy[4], d[N][N], r[N][N], c[N][N];
priority_queue < pair <int, pair<int, int>> > pq;

int n, m, k;

int main() {
  for (int i = 0; i < N; ++i) {
    fill(d[i], d[i] + N, oo);
  }
  scanf("%d %d %d", &n, &m, &k);
  dx[0] = dy[2] = k;
  dx[1] = dy[3] = -k;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      char ch;
      cin >> ch;
      if (ch == '.') {
        r[i][j] = 1;
        c[i][j] = 1;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      r[i][j] += r[i - 1][j];
    }
  }
  for (int j = 1; j <= m; ++j) {
    for (int i = 1; i <= n; ++i) {
      c[i][j] += c[i - 1][j];
    }
  }
  int x1, y1, x2, y2;
  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  pq.push({0, {x1, y1}});
  d[x1][y1] = 0;
  while (!pq.empty()) {
    int x = pq.top().second.first, y = pq.top().second.second;
    pq.pop();
    for (int i = 0; i < 4; ++i) {
      int x0 = x + dx[i], y0 = y + dy[i];
      
    }
  }
  if (d[x2][y2] == oo) {
    puts("-1");
  } else {
    printf("%d", d[x2][y2]);
  }
  return 0;
}