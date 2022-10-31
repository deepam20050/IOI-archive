// http://codeforces.com/problemset/problem/630/C

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  printf("%lld\n", (1LL << n + 1) - 2);
  return 0;
}