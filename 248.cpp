#include <bits/stdc++.h>

using namespace std;

const int N = 248;
const int M = 300;

int dp[N][N][M][2];
int a[N];

int n;

int F(int l, int r, int val, bool s) {
  if (l > r || r < 0 || r >= n || l < 0 || l >= n) {
    return -1;
  }
  int &ref = dp[l][r][val][s];
  if (ref != -1) {
    return ref;
  }
  ref = val;
  for (int i = l; i <= r; ++i) {
    ref = max(ref, a[i]);
  }
  // s is true : right
  // s is false : left
  if (s && a[r] == val) {
    ref = max(ref, max(a[r] + 1, F(l, r - 1, val + 1, s)));
  } else if (!s && a[l] == val){
    ref = max(ref, max(a[l] + 1, F(l + 1, r, val + 1, 0)));
  }
  for (int i = l + 1; i <= r; ++i) {
    if (a[i] == a[i - 1]) {
      int x = max(F(l, i - 2, 0, 1), max(a[i] + 1, F(i + 1, r, 0, 0)));
      int y = max(F(l, i - 2, a[i] + 1, 1), F(i + 1, r, 0, 0));
      int z = max(F(l, i - 2, 0, 1), F(i + 1, r, a[i] + 1, 0));
      ref = max(ref, max(x, max(y, z)));
    }
  }
  return ref;
}

int main() {
  // freopen("248.in", "r", stdin);
  // freopen("248.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  memset(dp, -1, sizeof dp);
  printf("%d", F(0, n - 1, 0, 1));
  return 0;
}