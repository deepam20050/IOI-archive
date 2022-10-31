#include <bits/stdc++.h>

using namespace std;

int main() {
  scanf("%d %d", &n, &pos);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", arr + i);
  }
  arr[n + 1] = pos;
  ++n;
  sort(arr + 1, arr + n + 1);
  for (int i = 2; i <= n; ++i) {
    sum[i] = sum[i - 1] + abs(abs(arr[i]) - abs(arr[i - 1]));
  }
  int idx = lower_bound(arr + 1, arr + n + 1, pos) - arr;
  long long ans = sum[n - 1] - sum[idx] + sum[n - 1], sum[idx] + sum[n - 1]
  return 0;
}