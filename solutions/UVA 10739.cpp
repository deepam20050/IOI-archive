// https://uva.onlinejudge.org/external/107/10739.pdf

#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int dp[N][N];
char s[N];

int n, t;

int F(int l, int r) {
  if (l >= r) {
    return 0;
  }
  int &ref = dp[l][r];
  if (ref != -1) {
    return ref;
  }
  ref = r - l;
  if (s[l] == s[r]) {
    ref = F(l + 1, r - 1);
  } else {
    ref = 1 + F(l + 1, r - 1);
  }
  return ref = min(ref, 1 + min(F(l + 1, r), F(l, r - 1)));
}

int main() {
  scanf("%d", &t);
  for (int _ = 1; _ <= t; ++_) {
    scanf("%s", s);
    n = strlen(s);
    memset(dp, -1, sizeof dp);
    printf("Case %d: %d\n", _, F(0, n - 1));
  }
  return 0;
}