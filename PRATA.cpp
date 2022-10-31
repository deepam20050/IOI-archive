// http://www.spoj.com/problems/PRATA/

#include <bits/stdc++.h>

using namespace std;

const int N = 123;

long long a[N];

int p;
int n;


bool F(int x) {
  long long cnt = 0;
  for (int i = 0; i < n; ++i) {
    cnt += ((-1) + sqrt(1 + 8 * x / a[i]))/2;
  }
  return cnt >= p;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &p, &n);
    for (int i = 0; i < n; ++i) {
      scanf("%lld", a + i);
    }
    long long l = 1, r = 1e8;
    for (int i = 0; i < 100; ++i) {
      int m = (l + r) >> 1LL;
      if (F(m)) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    printf("%lld\n", l);
  }
  return 0;
}