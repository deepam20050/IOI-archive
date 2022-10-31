#include <bits/stdc++.h>

using namespace std;

bool check (int x) {
  while (x) {
    int r = x % 10;
    if (r != 4 && r != 7) {
      return 0;
    }
    x /= 10;
  }
  return 1;
}

int main() {
  int sz = 0;
  for (int i = 4; i <= 10000; ++i) {
    if (check(i)) {
      lucky[sz++] = i;
    }
  }
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
  }
  while (m--) {
    scanf("%s", s);
    if (s[0] == 'a') {
      int x, y, z;
      scanf("%d %d %d", &x, &y, &z);
      update(1, 0, n - 1, x - 1, y - 1, z);
    } else {
      int x, y;
      scanf("%d %d", &x, &y);
      printf("%d\n", query(1, 0, n - 1, x - 1, y - 1));
    }
  }
  return 0;
}