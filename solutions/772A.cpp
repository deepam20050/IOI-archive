// http://codeforces.com/problemset/problem/772/A

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N];
int b[N];

int n;
long double p;

bool F(long double x) {
  long double sum = 0.0;
  for (int i = 0; i < n; ++i) {
    sum += double(max((long double)0.0, a[i] * x - b[i]) / x);
  }
  return sum <= p;
}

int main() {
  scanf("%d %Lf", &n, &p);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", a + i, b + i);
    sum += a[i];
  }
  if (sum <= p) {
    return 0 * puts("-1");
  }
  long double l = 0.0, r = 1e18;
  for (int i = 0; i < 100; ++i) {
    double m = (l + r) / 2.0;
    if (F(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  printf("%.9Lf\n", l);
  return 0;
}