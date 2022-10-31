// https://dmoj.ca/problem/hkccc15j4

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

pair <int, int> p[N];

int main() {
  int l, n;
  scanf("%d %d", &l, &n);
  int maxo = -1;
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &p[i].first, &p[i].second);
    maxo = max(maxo, p[i].second);
  }
  sort(p, p + n);
  int ans = max(p[0].first, l - maxo);
  int curr = p[0].second;
  for (int i = 1; i < n; ++i) {
    ans = max(ans, p[i].first - curr);
    curr = max(curr, p[i].second);
  }
  printf("%d", ans);
  return 0;
}