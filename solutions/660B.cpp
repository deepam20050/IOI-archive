// http://codeforces.com/problemset/problem/660/B

#include <bits/stdc++.h>

using namespace std;

const int N = 101;

int a[N][5];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1, j = 1; j <= n && i <= m; i += 2, ++j) {
    if (i + 1 <= m) {
      a[j][4] = i + 1;
      i + 1 + 2 * n <= m ? a[j][3] = i + 1 + 2 * n : a[j][3] = 0;
    }
    a[j][1] = i;
    i + 2 * n <= m ? a[j][2] = i + 2 * n : a[j][2] = 0;
  } 
  for (int i = 1; i <= n; ++i) {
    if (a[i][2]) {
      printf("%d ", a[i][2]);
    }
    if (a[i][1]) {
      printf("%d ", a[i][1]);
    }
    if (a[i][3]) {
      printf("%d ", a[i][3]);
    }
    if (a[i][4]) {
      printf("%d ", a[i][4]);
    }
  }
  return 0;
}

