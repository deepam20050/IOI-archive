// http://codeforces.com/problemset/problem/315/A
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int a[N], b[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", a + i, b + i);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        if (a[j] == b[i]) {
          ++ans;
          a[j] = -1;
        }
      }
    }
  }
  printf("%d\n", n - ans);
  return 0;
}

