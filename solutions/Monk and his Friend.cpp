// https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/monk-and-his-friend/

#include <bits/stdc++.h>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    int ans = 0;
    for (int i = 63; i >= 0; --i) {
      ans += ((a & (1LL << i)) != 0) ^ ((b & (1LL << i)) != 0);
    }
    printf("%d\n", ans);
  }
  return 0;
}