// http://www.spoj.com/problems/POSTERS/
// Nice problem on using sets

#include <bits/stdc++.h>

using namespace std;
using pi = pair <pair <int, int>, int>;

const int oo = 100000001, N = 40004;


struct comp {
  inline bool operator()(const pi &a, const pi &b) {
    return a.first.first < b.first.first && a.first.second < b.first.second;
  }
};

set <pi, comp> s;
bool ok[N];

int main() {
  int _;
  scanf("%d", &_);
  while (_--) {
    s.clear();
    memset(ok, 0, sizeof ok);
    s.insert({{0, 0}, 0});
    s.insert({{oo, oo}, 0});
    int n;
    scanf("%d", &n);
    for (int i = 1, x, y; i <= n; ++i) {
      scanf("%d %d", &x, &y);
      auto it1 = s.lower_bound({{x, x}, i});
      auto it2 = s.lower_bound({{y, y}, i});
      auto l = *it1;
      auto r = *it2;
      s.erase(it1, ++it2);
      if (l.first.first <= x && x <= l.first.second) {
        if (x - l.first.first > 0) {
          s.insert({{l.first.first, x - 1}, l.second});
        }
      } else if (l.first.first > y){
        s.insert(l);
      }
      if (r.first.first <= y && y <= r.first.second) {
        if (y + 1 <= r.first.second) {
          s.insert({{y + 1, r.first.second}, r.second});
        }
      } else {
        s.insert(r);
      }
      s.insert({{x, y}, i});
    }
    int ans = 0;
    for (const auto &e : s) {
      if (e.second == 0) {
        continue;
      }
      ans += !ok[e.second];
      ok[e.second] = 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}