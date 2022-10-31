// https://csacademy.com/contest/round-58/task/contiguous-segments/statement/
// Didn't change from int to long long and resulted in WA :(

#include <bits/stdc++.h>

using namespace std;

const int N = 2020;

pair <int, int> a[N];

int abso (int x) {
  return x < 0 ? -x : x;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &a[i].first, &a[i].second);
  }
  sort(a, a + n);
  long long ans = 1LL << 61;
  for (int i = 0; i < n; ++i) {
    long long res = 0;
    int curr = a[i].first;
    for (int j = i - 1; j >= 0; --j) {
      int rem = abso(curr - a[j].second);
      res += rem;
      if (a[j].second > curr) {
        curr = a[j].first - rem;
      } else {
        curr = a[j].first + rem;
      }
    }
    curr = a[i].second;
    for (int j = i + 1; j < n; ++j) {
      int rem = abso(curr - a[j].first);
      res += rem;
      if (a[j].first > curr) {
        curr = a[j].second - rem;
      } else {
        curr = a[j].second + rem;
      }
    }
    ans = min(ans, res);
  }
  printf("%lld\n", ans);
  return 0;
}