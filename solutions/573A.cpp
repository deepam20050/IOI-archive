// http://codeforces.com/problemset/problem/573/A
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
    while (a[i] % 2 == 0) {
      a[i] /= 2;
    }
    while (a[i] % 3 == 0) {
      a[i] /= 3;
    }
  }
  for (int i = 1; i < n; ++i) {
    if (a[i] != a[0]) {
      return !printf("No");
    }
  }
  printf("Yes");
  return 0;
}

