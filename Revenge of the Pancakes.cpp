// https://code.google.com/codejam/contest/dashboard?c=6254486#s=p1
// AC

#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("B-large-practice.in", "r", stdin);
  freopen("tout.out", "w", stdout);
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; ++tt) {
    printf("Case #%d: ", tt);
    string s;
    cin >> s;
    int n = s.size(), ans = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (ans & 1) {
        s[i] = s[i] == '+' ? '-' : '+';
      } 
      if (s[i] == '+') {
        continue;
      }
      ++ans;
    }
    printf("%d\n", ans);
  }
  return 0;
}