// http://www.spoj.com/problems/ADABEHIVE/

#include <bits/stdc++.h>

using namespace std;

const int N = 2010;

long long bit[N][N];

int n;
int m;
int q;

void update(int x, int y, long long add) {
  while (x <= n) {
    int j = y;
    while (j <= m) {
      bit[x][j] += add;
      j |= j + 1;
    }
    x |= x + 1;
  }
}

long long query(int x, int y) {
  long long sum = 0;
  while (x > 0) {
    int j = y;
    while (j > 0) {
      sum += bit[x][j];
      j &= j + 1;
      --j;
    }
    x &= x + 1;
    --x;
  }
  return sum;
}

int main() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      long long x;
      scanf("%lld", &x);
      update(i, j, x);
    }
  }
  while (q--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int x, y;
      long long z;
      scanf("%d %d %lld", &x, &y, &z);
      update(x, y, z);
    } else {
      int x1;
      int x2;
      int y1;
      int y2;
      scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
      printf("%lld\n", query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1));
    }
  }
  return 0;
}