// http://codeforces.com/problemset/problem/489/D

#include <bits/stdc++.h>

using namespace std;

const int N = 3010;

vector <int> in[N];
vector <int> out[N];
long long cnt[N][N];
int n, m;

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    in[y].emplace_back(x);
    out[x].emplace_back(y);
  }
  for (int i = 1; i <= n; ++i) {
    for (int x : in[i]) {
      for (int y : out[i]) {
        cnt[x][y] += 1 ? x != y : 0;
      }
    }
  }
  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= n; ++j) {
  //     cout << cnt[i][j] << " ";
  //   }
  //   cout << '\n';
  // }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      ans += (cnt[i][j] * (cnt[i][j] - 1)) >> 1LL;
    }
  }
  printf("%lld", ans);
  return 0;
}