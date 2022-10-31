// https://www.codechef.com/problems/SNAKEEAT
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

long long sum[N];
int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    sort(a, a + n);
    sum[0] = a[0];
    for (int i = 1; i < n; ++i) {
      sum[i] = sum[i - 1] + a[i];
    }
    while (q--) {
      int k;
      scanf("%d", &k);
      int r = lower_bound(a, a + n, k) - a;
      int l = 1, end = r;
      while (l < r) {
        int m = (l + r) / 2;
        long long req = 1LL * k * (end - m) - (sum[end - 1] - sum[m - 1]);
        if (req <= m) {
          r = m;
        } else {
          l = m + 1;
        }
      }
      printf("%d\n", n - r);
    }
  }
  return 0;
}
