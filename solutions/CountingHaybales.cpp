// http://www.usaco.org/index.php?page=viewproblem2&cpid=666

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N];

int main() {
  freopen("haybales.in", "r", stdin);
  freopen("haybales.out", "w", stdout);
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  while (q--) {
    int x, y;
    scanf("%d %d", &x, &y);
    int idx1 = upper_bound(a, a + n, y) - a;
    int idx2 = lower_bound(a, a + n, x) - a;
    printf("%d\n", idx1 - idx2);
  }
  return 0;
}