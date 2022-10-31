// http://www.spoj.com/problems/ABSP1/

#include <bits/stdc++.h>

using namespace std;

const int N = 10010;

long long a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", a + i);
    }
    long long s = 0, ans = 0;
    for (int i = 1; i <= n; s += a[i], ++i) {
      ans += (i - 1) * a[i] - s;
    }
    printf("%lld\n", ans);
  }
  return 0;
}