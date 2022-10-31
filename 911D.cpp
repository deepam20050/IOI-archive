// http://codeforces.com/contest/911/problem/D

#include <bits/stdc++.h>

using namespace std;

const int N = 1510;

int a[N];

int n;
int ans;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    for (int j = 0; j < i; ++j) {
      ans += a[j] > a[i];
    }
  }
  int q;
  scanf("%d", &q);
  int par = ans & 1;
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    int swaps = (r - l + 1) >> 1;
    int par2 = swaps & 1;
    par = (par + par2) & 1;
    par ? puts("odd") : puts("even");
  }
  return 0;
}