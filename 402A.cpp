// http://codeforces.com/problemset/problem/402/A

#include <bits/stdc++.h>

using namespace std;

int main() {
  int k, a, b, v;
  cin >> k >> a >> b >> v;
  for (int i = 1;; ++i) {
    int sections = min(b, k - 1) + 1;
    int each = min(a, sections * v);
    a -= each;
    b -= sections - 1;
    if (!a) {
      printf("%d\n", i);
      return 0;
    }
  }
  return 0;
}