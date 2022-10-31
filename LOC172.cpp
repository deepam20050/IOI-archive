#include <bits/stdc++.h>

using namespace std;

int main() {
  int h, w;
  while (scanf("%d %d", &h, &w) && h != -1) {
    int n;
    scanf("%d", &n);
    vector < pair <int, int> > v;
    for (int i = 0; i < n; ++i) {
      int x, y, d;
      scanf("%d %d %d", &x, &y, &d);
      v.push_back({y - d, 1});
      v.push_back({y + d, - 1});
    } 
    sort(v.begin(), v.end());
    int ans = 0, cnt = 0;
    for (const auto &e: v) {
      cnt += e.second;
      ans = max(ans, cnt);
    }
    printf("%d\n", ans);
  }
  return 0;
}

