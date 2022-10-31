// http://codeforces.com/problemset/problem/237/A
// AC

#include <bits/stdc++.h>

using namespace std;

map < pair <int, int>, int > mp;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int h, m;
    scanf("%d %d", &h, &m);
    ++mp[make_pair(h, m)];
  }
  int ans = -1;
  for (const auto &e: mp) {
    ans = max(e.second, ans);
  }
  printf("%d\n", ans);
  return 0;
}

