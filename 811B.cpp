// http://codeforces.com/contest/811/problem/B
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 10010;

int a[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  while (m--) {
    int l, r, x;
    scanf("%d %d %d", &l, &r, &x);
    int num = 0, pos = l;
    while (l <= r) {
      if (a[l] <= a[x]) {
        ++num;
      }
      ++l;
    }
    if (num == x - pos + 1) {
      puts("Yes");
    } else {
      puts("No");
    }
  }
  return 0;
}

