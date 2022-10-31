// http://codeforces.com/problemset/problem/451/B
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

long a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%ld", a + i);
  }
  if (is_sorted(a, a + n)) {
    return !printf("yes\n1 1");
  }
  int l = 0, r = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i] < a[i - 1]) {
      l = i - 1;
      break;
    }
  }
  for (int i = n - 2; i >= 0; --i) {
    if (a[i] > a[i + 1]) {
      r = i + 1;
      break;
    }
  }
  reverse(a + l, a + r + 1);
  if (is_sorted(a, a + n)) {
    printf("yes\n%d %d", l + 1, r + 1);
  } else {
    puts("no");
  }
  return 0;
}

