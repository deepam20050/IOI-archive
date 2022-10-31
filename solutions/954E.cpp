// http://codeforces.com/contest/954/problem/E

#include <bits/stdc++.h>

using namespace std;
using ld = long double;

const int N = 2e5 + 1;

pair <ld, ld> arr[N];

int main() {
  int n;
  long long t;
  scanf("%d %lld", &n, &t);
  for (int i = 0; i < n; ++i) {
    scanf("%Lf", &arr[i].second);
  }
  ld sum = 0;
  ld ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%Lf", &arr[i].first);
    arr[i].first -= t;
    sum += arr[i].first * arr[i].second;
    ans += arr[i].second;
  }
  if (!sum) {
    return printf("%Lf\n", ans), 0;
  }
  if (sum < 0) {
    for (int i = 0; i < n; ++i) {
      arr[i].first = -arr[i].first;
    }
    sum = -sum;
  }
  sort(arr, arr + n, greater <pair <ld, ld>> ());
  for (int i = 0; i < n; ++i) {
    if (arr[i].first <= 0) {
      break;
    }
    if (sum > arr[i].first * arr[i].second) {
      sum -= arr[i].first * arr[i].second;
      ans -= arr[i].second;
    } else {
      return printf("%.10Lf\n", (long double)(ans - (long double)sum / arr[i].first)), 0;
    }
  }
  printf("%.10Lf\n", ans);
  return 0;
}