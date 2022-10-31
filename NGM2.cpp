// http://www.spoj.com/problems/NGM2/

#include <bits/stdc++.h>

using namespace std;

unsigned long long arr[15];

int main() {
  unsigned long long n;
  int k;
  scanf("%llu %d", &n, &k);
  for (int i = 0; i < k; ++i) {
    scanf("%llu", arr + i);
  }
  unsigned long long sum = 0;
  for (int mask = 1; mask < (1 << k); ++mask) {
    int cnt = 0;
    unsigned long long mult = 1;
    for (int i = 0; i < k; ++i) {
      if (mask & (1 << i)) {
        ++cnt;
        mult = (mult * arr[i]) / __gcd(mult, arr[i]);
        if (mult > n) {
          cnt = -1;
          break;
        }
      }
    }
    if (cnt != -1) {
      if (cnt & 1) {
        sum += n / mult;
      } else {
        sum -= n / mult;
      }
    }
  }
  printf("%llu", n - sum);
  return 0;
}