// http://codeforces.com/contest/908/problem/C

#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int x[N];
double y[N];

int n, r;

int main() {
  scanf("%d %d", &n, &r);
  for (int i = 0; i < n; ++i) {
    scanf("%d", x + i);
    double ans = r;
    for (int j = 0; j < i; ++j) {
      int d = abs(x[j] - x[i]);
      if (d > r + r) {
        continue;
      }
      if (d == r + r) {
        ans = max(ans, y[j]);
        continue;
      }
      double dy = sqrt(4 * r * r - d * d);
      ans = max(ans, dy + y[j]);
    }
    y[i] = ans;
    printf("%.9lf ", y[i]);
  }
  return 0;
}