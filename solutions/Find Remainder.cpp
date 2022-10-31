// https://csacademy.com/contest/archive/task/find-remainder/solution/

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N];

int n;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  int gcd = 0;
  int mx = 1;
  for (int i = 0; i < n; ++i) {
    int b;
    scanf("%d", &b);
    a[i] -= b;
    if (a[i] < 0) {
      return !printf("-1");
    }
    gcd = __gcd(a[i], gcd);
    mx = max(mx, b + 1);
  }
  if (!gcd) {
    return !printf("%d", mx);
  }
  if (mx > gcd) {
    return !printf("-1");
  }
  int ans = gcd;
  for (int i = 1; i * i <= gcd; ++i) {
    if (gcd % i == 0) {
      if (i >= mx) {
        ans = min(ans, i);
      } 
      if (gcd / i >= mx) {
        ans = min(ans, gcd / i);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}