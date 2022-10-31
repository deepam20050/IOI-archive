// https://dmoj.ca/problem/ccc08s4

#include <bits/stdc++.h>

using namespace std;

const int oo = 1 << 28;

int a[4];

int calc(int i, int a, int b) {
  if (i == 0) {
    return a + b;
  }
  if (i == 1) {
    return a - b;
  }
  if (i == 2) {
    return a * b;
  }
  if (b == 0) {
    return oo;
  }
  return a % b == 0 ? a / b : oo;
}

void get(int a, int &b) {
  if (a <= 24 && a > b) {
    b = a;
  }
}

int solve (int a, int b, int c, int d) {
  int val = 0;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      for (int k = 0; k < 4; ++k) {
        int q = calc(j, calc(i, a, b), calc(k, c, d));
        int w = calc(k, calc(j, calc(i, a, b), c), d);
        int e = calc(i, a, calc(k, calc(j, b, c), d));
        int r = calc(i, a, calc(j, b, calc(k, c, d)));
        get(q, val);
        get(w, val);
        get(e, val);
        get(r, val);
      }
    }
  }
  return val;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < 4; ++i) {
      scanf("%d", a + i);
    }
    int val = 0;
    do {
      int res = solve(a[0], a[1], a[2], a[3]);
      get(res, val);
    } while (next_permutation(a, a + 4));
    printf("%d\n", val);
  }
  return 0;
}