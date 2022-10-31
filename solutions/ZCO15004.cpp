#include <bits/stdc++.h>

using namespace std;

const int N = 100010, Y = 500, X = 100000;

pair <int, int> a[N];
stack < pair <int, int> > s;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    a[i] = {x, y};
  }
  a[n] = {X, Y};
  sort(a, a + n + 1);
  int ans = 0;
  s.push({0, 0});
  for (int i = 0; i <= n; ++i) {
    int mini = Y;
    while (!s.empty()) {
      ans = max(ans, (a[i].first - s.top().first) * mini);
      mini = min(mini, s.top().second);
      if (s.top().second < a[i].second) {
        break;
      }
      s.pop();
    }
    ans = max(ans, (a[i].first - s.top().first) * mini);
    s.push({a[i].first, a[i].second});
  }
  printf("%d\n", ans);
  return 0;
}