// http://codeforces.com/problemset/problem/131/C

#include <bits/stdc++.h>

using namespace std;

const int N = 62;

long long pascal[N][N];

int main() {
  for(int i = 0 ; i < N ; ++i){
    pascal[i][0] = 1;
    for(int j = 1 ; j <= i ; ++j){
      pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
    }
  }
  int n, m, t;
  scanf("%d %d %d", &n, &m, &t);
  long long ans = 0;
  for (int i = 4; i < t; ++i) {
    long long tmp = 0;
    if (m >= t - i) {
      tmp = pascal[m][t - i];
    }
    if (n >= i && tmp) {
      tmp *= pascal[n][i];
    } else {
      tmp = 0;
    }
    ans += tmp;
  }
  printf("%lld\n", ans);
  return 0;
}