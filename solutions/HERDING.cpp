// http://www.spoj.com/problems/HERDING/

#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int used[N][N];
char s[N][N];

int cnt = 1, ans;

void dfs(int i, int j) {
  if (!used[i][j]) {
    used[i][j] = cnt;
  } else {
    if (used[i][j] == cnt) {
      return;
    } else {
      --ans;
      return ;
    } 
  }
  if (s[i][j] == 'N') {
    dfs(i - 1, j);
  }
  if (s[i][j] == 'S') {
    dfs(i + 1, j);
  }
  if (s[i][j] == 'E') {
    dfs(i, j + 1);
  }
  if (s[i][j] == 'W') {
    dfs(i, j - 1);
  }
}


int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!used[i][j]) {
        dfs(i, j);
        ++ans;
        ++cnt;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}