// http://codeforces.com/problemset/problem/287/A
// AC

#include <bits/stdc++.h>

using namespace std;

char grid[4][4];

void add(int i, int j, int &b, int &w) {
  if (grid[i][j] == '#') {
    ++b;
  } else {
    ++w;
  }
}

int main() {
  for (int i = 0; i < 4; ++i) {
    scanf("%s", grid[i]);
  }
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      int b = 0, w = 0;
      add(i, j, b, w);
      add(i, j + 1, b, w);
      add(i + 1, j, b, w);
      add(i + 1, j + 1, b, w);
      if (w != 2 && b != 2) {
        return !printf("YES");
      }
    }
  }
  printf("NO");
  return 0;
}

