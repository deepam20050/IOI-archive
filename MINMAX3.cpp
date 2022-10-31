// https://www.codechef.com/problems/MINMAX3

#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int a[N];
long long z[N];

int n, k;

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 0; i + 1 < n; ++i) {
    z[i] = a[i] + a[i + 1];
  }
  int m = n - 1;
  sort(z, z + m);
  long long s1 = a[0] + a[n - 1] + accumulate(z, z + k - 1, 0LL);
  sort(z, z + m, greater <int> ());
  long long s2 = a[0] + a[n - 1] + accumulate(z, z + k - 1, 0LL);
  printf("%lld %lld", s1, s2);
  return 0;
}