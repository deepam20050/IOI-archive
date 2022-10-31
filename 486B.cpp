// http://codeforces.com/problemset/problem/486/B
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int row[N], col[N];
int grid[N][N], ans[N][N];

int main() {
  for (int i = 0; i < N; ++i) {
    row[i] = col[i] = -1;
  }
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &grid[i][j]);
      if (!grid[i][j]) {
        row[i] = col[j] = 0;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    bool flag = 0;
    for (int j = 0; j < m; ++j) {
      if (col[j] == -1) {
        flag = 1;
        break;
      }
    }
    if (!flag) {
      row[i] = 0;
    }
  }
  for (int j = 0; j < m; ++j) {
    bool flag = 0;
    for (int i = 0; i < n; ++i) {
      if (row[i] == -1) {
        flag = 1;
        break;
      }
    }
    if (!flag) {
     col[j] = 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!grid[i][j]) {
        continue;
      } else if (row[i] == 0 && col[j] == 0) {
        return !printf("NO");
      } else if (row[i] == -1 && col[j] == -1) {
        ans[i][j] = 1;
      }
    }
  }
  puts("YES");
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      printf("%d ", ans[i][j]);
    }
    putchar('\n');
  }
  return 0;
}

