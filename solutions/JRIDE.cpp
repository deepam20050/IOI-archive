// http://www.spoj.com/problems/JRIDE/

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int mini[N];
int sum[N];
int a[N];
int l[N];

int main() {
  int _;
  scanf("%d", &_);
  for (int r = 1; r <= _; ++r) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
      scanf("%d", a + i);
    }
    for (int i = 1; i < n; ++i) {
      sum[i] = sum[i - 1] + a[i];
      mini[i] = sum[i];
      l[i] = i;
    }
    for (int i = 1; i < n; ++i) {
      if (mini[i] >= mini[i - 1]) {
        mini[i] = mini[i - 1];
        l[i] = l[i - 1];
      }
    }
    int ans = 0;
    int s = -1;
    int e = -1;
    for (int i = 1; i < n; ++i) {
      if (sum[i] - mini[i] > ans) {
        e = i;
        s = l[i];
        ans = sum[i] - mini[i];
      } else if (ans == sum[i] - mini[i - 1] && (i - l[i] > e - s)) {
        e = i;
        s = l[i];
      }
    }
    if (ans <= 0) {
      printf("Route %d has no nice parts\n", r);
    } else {
      printf("The nicest part of route %d is between stops %d and %d\n", r, s + 1, e + 1);
    }
  }
  return 0;
}