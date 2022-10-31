// https://arc092.contest.atcoder.jp/tasks/arc092_a

#include <bits/stdc++.h>

using namespace std;

vector < pair <int, pair <int, int> > > v;
multiset <int> stt;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    v.push_back({x, {y, 0}});
  }
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    v.push_back({x, {y, 1}});
  }
  sort(v.begin(), v.end());
  int ans = 0;
  for (auto &e : v) {
    int x = e.first;
    int y = e.second.first;
    int op = e.second.second;
    if (!op) {
      stt.insert(y);
    } else {
      auto it = stt.lower_bound(y);
      if (it != stt.begin()) {
        --it;
        ++ans;
        stt.erase(it);
      }
    }
  }
  cout << ans;
  return 0;
}