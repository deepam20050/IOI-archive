// https://codeforces.com/problemset/problem/43/C

#include <bits/stdc++.h>

using namespace std;

int v[3];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    ++v[x % 3];
  }
  int ans = (v[0] >> 1) + min(v[1], v[2]);
  printf("%d\n", ans);
  return 0;
}