// https://csacademy.com/contest/round-59/task/triangular-matrix/solution/

#include <bits/stdc++.h>

using namespace std;

vector <int> v;
vector <int> t;
char s[3010];
char ans[3010];

int main() {
  int n;
  scanf("%d", &n);
  v.push_back(0);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s);
    char c = 'z';
    for (int j : v) {
      c = min(c, s[j]);
    }
    ans[i - 1] = c;
    t.clear();
    for (int j : v) {
      if (c == s[j]) {
        if (t.empty() || t.back() < j) {
          t.push_back(j);
        }
        t.push_back(j + 1);
      }
    }
    v = t;
  }
  ans[n] = 0;
  puts(ans);
  return 0;
}