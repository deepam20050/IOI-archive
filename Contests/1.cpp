#include <bits/stdc++.h>

using namespace std;

inline void compute (int &ans, int fa, int fb, int a, int b) {
  if (a <= fa && fa <= b) {
    ans += abs(fa - fb);
  } else if (fa <= a) {
    ans += a - fa + abs(fb - a);
  } else {
    ans += fa - b + abs(fb - b);
  }
}

int main() {
  int n, h, a, b, k;
  cin >> n >> h >> a >> b >> k;
  while (k--) {
    int ta, fa, tb, fb;
    cin >> ta >> fa >> tb >> fb;
    int ans1 = abs(ta - tb);
    int ans2 = abs(ta - tb);
    compute(ans1, fa, fb, a, b);
    compute(ans2, fb, fa, a, b);
    cout << min(ans1, ans2) << '\n';
  }
  return 0;
}