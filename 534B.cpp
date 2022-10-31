// http://codeforces.com/problemset/problem/534/B
// AC

#include <bits/stdc++.h>

using namespace std;

int abso(int x) {
  return x < 0 ? -x : x;
}

int main() {
  int v1, v2, t, d;
  scanf("%d %d %d %d", &v1, &v2, &t, &d);
  int ans = v1;
  int curr = v1;
  for (int i = 1; i < t; ++i) {
    int add = 0;
    for (int dd = d; dd >= -d; --dd) {
      add = curr + dd;
      if (abso(add - v2) <= (t - i - 1) * d) {
        break;
      }
    }
    ans += add;
    curr = add;
  }
  printf("%d\n", ans);
  return 0;
}
