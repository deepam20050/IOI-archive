// https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/monks-choice-of-numbers-1/description/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int arr[N];
int tc;
int n;
int k;

int main() {
  scanf("%d", &tc);
  while (tc--) {
    scanf("%d %d", &n, &k);
    for (int i = 1, x; i <= n; ++i) {
      scanf("%d", &x);
      arr[i] = __builtin_popcount(x);
    }
    sort(arr + 1, arr + n + 1, greater <int> ());
    int ans = 0;
    for (int i = 1; i <= k; ++i) {
      ans += arr[i];
    }
    printf("%d\n", ans);
  }
  return 0;
}