// https://www.codechef.com/problems/L56LABY

#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int arr[N][N];
int dist[N][N];
priority_queue < pair <int, pair <int, int> > > pq;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        scanf("%d", arr[i] + j);
        dist[i][j] = -2e9;
        if (arr[i][j] > 0) {
          pq.push({arr[i][j], {i, j}});
          dist[i][j] = arr[i][j];
        }
      }
    }
    while (!pq.empty()) {
      int x = pq.top().second.first;
      int y = pq.top().second.second;
      int step = pq.top().first;
      pq.pop();
      if (!step) {
        continue;
      }
      for (int i = 0; i < 4; ++i) {
        int x0 = x + dx[i];
        int y0 = y + dy[i];
        if (x0 > 0 && x0 <= n && y0 > 0 && y0 <= m && arr[x0][y0] != -1 && dist[x0][y0] < dist[x][y] - 1) {
          dist[x0][y0] = dist[x][y] - 1;
          pq.push({dist[x0][y0], {x0, y0}});
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (arr[i][j] == -1) {
          putchar('B');
        } else if (arr[i][j] > 0) {
          putchar('Y');
        } else if (dist[i][j] >= 0) {
          putchar('Y');
        } else {
          putchar('N');
        }
      }
      putchar('\n');
    }
  }
  return 0;
}