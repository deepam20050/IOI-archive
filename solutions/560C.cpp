// http://codeforces.com/contest/560/problem/C
// Good problem on Geometry! :D

#include <bits/stdc++.h>

using namespace std;

int sqr(int x) {
  return x * x;
}

int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  printf("%d", sqr(a + b + c) - sqr(a) - sqr(c) - sqr(e));
  return 0;
}