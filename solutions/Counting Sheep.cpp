// https://code.google.com/codejam/contest/dashboard?c=6254486#s=p0
// AC

#include <bits/stdc++.h>

using namespace std;

int d[10];

void count(int n) {
  while (n) {
    ++d[n % 10];
    n /= 10;
  }
}

bool check() {
  for (int i = 0; i < 10; ++i) {
    if (!d[i]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  freopen("A-large-practice.in", "r", stdin);
  freopen("tout.out", "w", stdout);
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; ++tt) {
    int n;
    scanf("%d", &n);
    memset(d, 0, sizeof d);
    count(n);
    if (check()) {
      printf("Case #%d: %d\n", tt, n);
      continue;
    }
    bool flag = 0;
    int i = 2;
    for (; i <= 1000; ++i) {
      count(n * i);
      if (check()) {
        flag = 1;
        break;
      }
    }
    printf("Case #%d: ", tt);
    flag ? printf("%d\n", n * i) : puts("INSOMNIA");
  }
  return 0;
}