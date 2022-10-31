// https://codeforces.com/problemset/problem/903/C

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector < int > arr(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }
  sort(arr.begin(), arr.end());
  int ans = n;
  vector < bool > yes(n, 0);
  for (int i = 1; i < n; ++i) {
    for (int j = i - 1; j >= 0; --j) {
      if (!yes[j] && arr[i] > arr[j]) {
        yes[j] = 1;
        --ans;
        break;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}