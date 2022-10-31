// http://codeforces.com/contest/922/problem/B

#include <bits/stdc++.h>

using namespace std;

bool check (int a, int b, int c) {
  if (a + b <= c) {
    return 0;
  }
  if (a + c <= b) {
    return 0;
  }
  if (b + c <= a) {
    return 0;
  }
  if (abs(a - b) >= c) {
    return 0;
  }
  if (abs(a - c) >= b) {
    return 0;
  }
  if (abs(b - c) >= a) {
    return 0;
  }
  return 1;
}

int main() {
  int n;
  scanf("%d", &n);
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      int k = i ^ j;
      if (k < j || k > n) {
        continue;
      }
      ans += check(i, j, k);
    }
  }
  printf("%d\n", ans);
  return 0;
}