// http://codeforces.com/problemset/problem/450/B
// AC

#include <bits/stdc++.h>

using namespace std;

const long md = 1e9 + 7;

int main() {
  long x, y, n;
  scanf("%ld %ld %ld", &x, &y, &n);
  long ans = 0;
  if (n % 6 == 0) {
    ans = -y + x;
  } else if (n % 6 == 1) {
    ans = x;
  } else if (n % 6 == 2) {
    ans = y;
  } else if (n % 6 == 3) {
    ans = y - x;
  } else if (n % 6 == 4) {
    ans = -x;
  } else {
    ans = -y;
  }
  ans %= md;
  if (ans < 0) {
    ans = md + ans;
  }
  printf("%ld\n", ans);
  return 0;
}

