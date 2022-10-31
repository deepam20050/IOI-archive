#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 50;

long long bit[N];
long long l[N];
long long r[N];
long long b[N];

int n;
int q;
long long p;

void update (int idx, long long x) {
  while (idx < n) {
    bit[idx] *= x;
    bit[idx] %= p;
    idx |= idx + 1;
  }
}

long long query (int idx) {
  long long ans = 1;
  while (idx >= 0) {
    ans *= bit[idx];
    ans %= p;
    idx = (idx & (idx + 1)) - 1;
  }
  return ans;
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%d %lld %d", &n, &p, &q);
    fill(bit, bit + n, 1);
    for (int i = 0; i < n; ++i) {
      long long x;
      scanf("%lld", &x);
      update(i, x);
    }
    int sz = q / 64 + 2;
    for (int i = 0; i < sz; ++i) {
      scanf("%lld", b + i);
    }
    long long x = 0;
    for (int i = 0; i < q; ++i) {
      if (i % 64) {
        l[i] = (l[i - 1] % n + x % n) % n;
        r[i] = (r[i - 1] % n + x % n) % n;
      } else {
        l[i] = (b[i / 64] % n + x % n) % n;
        r[i] = (b[i / 64 + 1] % n + x % n) % n;
      }
      if (l[i] > r[i]) {
        swap(l[i], r[i]);
      }
      x = query(r[i]) / query(l[i] - 1) % p + 1;
      x %= p;
    }
    printf("%lld\n", x);
  }
  return 0;
}