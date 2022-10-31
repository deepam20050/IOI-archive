// http://www.spoj.com/problems/DCEPC206/

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

long long bit[N];
vector < pair <long long, int> > v;

int n;

void update(int idx, long long add) {
  while (idx <= n) {
    bit[idx] += add;
    idx |= idx + 1;
  }
}

long long query(int idx) {
  long long ret = 0;
  while (idx > 0) {
    ret += bit[idx];
    idx &= idx + 1;
    --idx;
  }
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    v.clear();
    memset(bit, 0, sizeof bit);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      long long x;
      scanf("%lld", &x);
      v.push_back({x, i});
      v.push_back({x, -i});
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    for (const auto &e : v) {
      long long a = e.first;
      int b = e.second;
      if (b < 0) {
        ans += query(-b);
      } else {
        update(b, a);
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}