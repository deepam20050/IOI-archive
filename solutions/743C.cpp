// http://codeforces.com/contest/743/problem/C
// AC

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  if (n == 1) {
    return !printf("-1");
  } 
  printf("%d %d %d", n, n + 1, n * (n + 1));
  return 0;
}

