// http://poj.org/problem?id=2386

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <cctype>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <vector>
#include <utility>

using namespace std;

const int N = 110;

char s[N][N];
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
bool used[N][N];

int n, m;

void dfs(int x, int y) {
  used[x][y] = 1;
  for (int i = 0; i < 8; ++i) {
    int x0 = x + dx[i], y0 = y + dy[i];
    if (0 <= x0 && x0 < n && 0 <= y0 && y0 < m) {
      if (!used[x0][y0] && s[x0][y0] == 'W') {
        dfs(x0, y0); 
      }
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!used[i][j] && s[i][j] == 'W') {
        dfs(i, j);
        ++ans;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}