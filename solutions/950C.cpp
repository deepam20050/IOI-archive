// http://codeforces.com/contest/950/problem/C

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;

char s[N];
vector <int> v[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int idx = 0, sz = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      v[idx++].emplace_back(i + 1);
    } else {
      if (idx == 0) {
        puts("-1");
        return 0;
      }
      v[--idx].emplace_back(i + 1);
    }
    sz = max(sz, idx);
  }
  if (sz != idx) {
    return 0 * puts("-1");
  }
  printf("%d\n", idx);
  for (int i = 0; i < idx; ++i) {
    printf("%d", v[i].size());
    for (int x : v[i]) {
      printf(" %d", x);
    }
    puts("");
  } 
  return 0;
}