// http://www.spoj.com/problems/BOOKS1/

#include <bits/stdc++.h>

using namespace std;

int a[510];

int n, k;

bool F(int x) {
  int curr = 0;
  int need = 1;
  for (int i = 0; i < n; ++i) {
    if (a[i] > x) {
      return 0;
    }
    if (curr + a[i] > x) {
      ++need;
      curr = 0;
    }
    curr += a[i];
  }
  return need <= k;
}

void print(int idx, int limit, int left) {
  int i = idx;
  int curr = 0;
  for (; i >= 0; --i) {
    if (curr + a[i] > limit || i + 1 == left - 1) {
      print(i, limit, left - 1);
      break;
    }
    curr += a[i];
  }
  if (i >= 0) {
    printf("/ ");
  }
  ++i;
  while (i <= idx) {
    printf("%d", a[i]);
    if (i != n - 1) {
      putchar(' ');
    }
    ++i;
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &k);
    int l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
      r += a[i];
    }
    for (int i = 0; i < 30; ++i) {
      int x = (l + r) >> 1LL;
      if (F(x)) {
        r = x;
      } else {
        l = x + 1;
      }
    }
    print(n - 1, r, k);
    putchar('\n');
  }
  return 0;
}