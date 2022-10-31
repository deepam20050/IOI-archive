// https://www.codechef.com/OCT17/problems/CHEFCCYL

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int tot[N], cycle[N], u[N], v[N];
vector <int> sum[N];

int n, q;

int calc(int c, int x, int y) {
  if (x > y) {
    swap(x, y);
  }
  return min(sum[c][y] - sum[c][x], tot[c] - sum[c][y] + sum[c][x]);  
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i) {
      tot[i] = cycle[i] = 0;
      sum[i].clear();
      sum[i] = {0, 0}; 
      int m;
      scanf("%d", &m);
      for (int j = 1, x; j <= m; ++j) {
        scanf("%d", &x);
        tot[i] += x;
        if (j % m + 1 != 1) {
          sum[i].emplace_back(sum[i][j] + x);
        }
      }
    }
    int sara = 0;
    for (int i = 1; i <= n; ++i) {
     int x, y, z;
     scanf("%d %d %d", &x, &y, &z);
     v[i] = x;
     u[i % n + 1] = y;
     sara += z;
     if (i % n + 1 != 1) {
       cycle[i % n + 1] += z;
     }
    }
    for (int i = 1; i <= n; ++i) {
      sara += calc(i, u[i], v[i]);
      cycle[i] += calc(i, u[i], v[i]) + cycle[i - 1];
    }
    while (q--) {
      int v1, c1, v2, c2;
      scanf("%d %d %d %d", &v1, &c1, &v2, &c2);
      if (c2 < c1) {
        swap(c2, c1);
        swap(v2, v1);
      }
      printf("%d\n", min(cycle[c2] - cycle[c1] + calc(c1, v1, v[c1]) - calc(c2, u[c2], v[c2]) + calc(c2, u[c2], v2), sara - (cycle[c2] - cycle[c1]) - calc(c1, u[c1], v[c1]) + calc(c1, u[c1], v1) + calc(c2, v[c2], v2)));
    }
  }
  return 0;
}