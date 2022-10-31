// http://codeforces.com/problemset/problem/893/D

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N];

int main() {
  int n, d, s = 0;
  scanf("%d %d", &n, &d);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    s += a[i];
    if (!a[i]) {
      s = max(s, 0);
    } else {
      if (s > d) {
        return puts("-1"), 0;
      }
    }
  }
  s = 0;
  int days = 0;
  for (int i = 0; i < n; ++i) {
    if (!a[i] && s < 0) {
      ++days;
      s = d;
    } else {
      s += a[i];
      s = min(s, d);
    }
  }
  printf("%d\n", days);
  return 0;
}