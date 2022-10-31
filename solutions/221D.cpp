// http://codeforces.com/contest/220/problem/B

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int cnt[N];
vector <int> g[N];
vector < vector <int> > v;
int vrr[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1, x; i <= n; ++i) {
    scanf("%d", &x);
    if (x <= n) {
      g[x].emplace_back(i);
      ++cnt[x];
    }
  }
  int j = 0;
  for (int i = 1; i <= n; ++i) {
    if (cnt[i] >= i) {
      vector <int> vec;
      for (int x : g[i]) {
        vec.emplace_back(x);
      }
      v.emplace_back(vec);
      vrr[j++] = i;
    }
  }
  // There are atmost √N numbers as 1 + 2 + 3 + ... = K * (K + 1) / 2 ≤ √N
  while (m--) {
    int ans = 0;
    int x, y;
    scanf("%d %d", &x, &y);
    int k = 0;
    for (auto &vec : v) {
      int howmany = upper_bound(vec.begin(), vec.end(), y) - lower_bound(vec.begin(), vec.end(), x);
      ans += howmany == vrr[k++];
    }
    printf("%d\n", ans);
  }
  return 0;
}