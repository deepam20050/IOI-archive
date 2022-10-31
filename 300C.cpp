#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

int a, b, n;

inline bool yes (int x) {
  while (x) {
    int val = x % 10;
    if (val != a && val != b) {
      return 0;
    }
    x /= 10;
  }
  return 1;
}

int main() {
  scanf("%d %d %d", &a, &b, &n);
  long long ans = 0;
  for (int x = 0; x <= n; ++x) {
    int y = n - x;
    if (yes(a * x + b * y)) {

    }
  }
  printf("%lld\n", ans);
  return 0;
}