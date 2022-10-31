// http://www.spoj.com/problems/NICEDAY/problem/

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

pair <int, pair <int, int>> p[N];
int bit[N];

int n;

void update (int idx, int val) {
  while (idx <= n) {
    bit[idx] = min(bit[idx], val);
    idx += idx & -idx;
  }
}

int query(int idx) {
  int res = 1 << 30;
  while (idx) {
    res = min(res, bit[idx]);
    idx -= idx & -idx;
  }
  return res;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d %d %d", &p[i].first, &p[i].second.first, &p[i].second.second);
    }
    sort(p + 1, p + n + 1);
    fill(bit + 1, bit + n + 1, 1 << 30);
    int res = 0;
    for (int i = 1; i <= n; ++i) {
      int val = query(p[i].second.first);
      if (val > p[i].second.second) {
        ++res;
      }
      update(p[i].second.first, p[i].second.second);
    }
    printf("%d\n", res);
  }
  return 0;
}