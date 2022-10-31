// http://codeforces.com/contest/794/problem/B
// AC

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, h;
  scanf("%d %d", &n ,&h);
  for (double i = 1.0; i < (double)n; i += 1.0) {
    printf("%.10f ", h * sqrt(i/(double)n));
  }
  return 0;
}