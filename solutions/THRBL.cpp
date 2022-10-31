// http://www.spoj.com/problems/THRBL/

#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;
const int MAXK = 17;

int lg[N];
int arr[N];
int ST[N][MAXK];
int n;
int m;

inline void precomp () {
  lg[1] = 0;
  for (int i = 2; i < N; ++i) {
    lg[i] = lg[i >> 1] + 1;
  }
  for (int i = 1; i <= n; ++i) {
    ST[i][0] = arr[i];
  }
  for (int j = 1; j < MAXK; ++j) {
    for (int i = 1; i + (1 << j) <= n; ++i) {
      ST[i][j] = max(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
    }
  }
}

inline int query (int l, int r) {
  int j = lg[r - l + 1];
  return max(ST[l][j], ST[r - (1 << j) + 1][j]);
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", arr + i);
  }
  precomp();
  int ans = 0;
  while (m--) {
    int l, r;
    scanf("%d %d", &l, &r);
    ans += query(l, r - 1) <= arr[l];
  } 
  printf("%d\n", ans);
  return 0;
}