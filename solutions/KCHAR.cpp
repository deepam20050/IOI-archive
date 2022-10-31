#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll getpow(ll x) {
  ll p = 1;
  while (p <= x) {
    p <<= 1;
  }
  return p >> 1;
} 

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    ll k;
    scanf("%d", &k);
    while (k != 1) {
      ll nearest = getpow(k) - k;
      if (nearest == k) {
        puts("a");
        break;
      }
    }
  }
  return 0;
}

