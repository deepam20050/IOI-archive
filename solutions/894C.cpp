// http://codeforces.com/contest/894/problem/C

#include <bits/stdc++.h>

using namespace std;

const int N = 4010;

int a[N];

int main() {
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", a + i);
  }
  int hcf = a[0];
  for (int i = 0; i < m; ++i) {
    if (a[i] % hcf) {
      return 0 * puts("-1");
    }
  }
  printf("%d\n", (m << 1));
  for (int i = 0; i < m; ++i) {
    printf("%d %d ", hcf, a[i]);
  }
  return 0;
}