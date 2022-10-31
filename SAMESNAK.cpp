#include <bits/stdc++.h>

using namespace std;

bool check(long x, long y, long x1, long y1) {
  return (x == x1) && (y == y1);
}

void solve(long x0, long y0, long x1, long y1, long x2, long y2, long x3, long y3) {
  if (y2 == y3) {
    if (y2 == y0 && ((x0 <= x2 && x2 <= x1) || (x0 <= x3 && x3 <= x1))) {
      puts("yes");
    } else {
      puts("no");
    }
    return;
  } else if (check(x0, y0, x2, y2) || check(x0, y0, x3, y3) || check(x1, y1, x2, y2) || check(x1, y1, x3, y3)) {
    puts("yes");
    return;
  }
  puts("no");
  return;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long x0, y0, x1, y1, x2, y2, x3, y3;
    scanf("%ld %ld %ld %ld %ld %ld %ld %ld", &x0, &y0, &x1, &y1, &x2, &y2, &x3, &y3);
    if (y1 == y0) {
      solve(x0, y0, x1, y1, x2, y2, x3, y3);
    } else {
      swap(x0, y0);
      swap(x1, y1);
      //swap(x2, y2);
      //swap(x3, y3);
      solve(x0, y0, x1, y1, x2, y3, x3, y3);
    }
  }
  return 0;
}

