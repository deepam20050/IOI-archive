// http://codeforces.com/problemset/problem/630/F

#include <bits/stdc++.h>

using namespace std;

const int N = 780;

unsigned long long pascal[N][9];

int main() {
  for (int i = 0; i < N; ++i) {
    pascal[i][0] = 1LL;
    for (int j = 1; j < min(i, 8); ++j) {
      pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
    }
  }
  int n;
  scanf("%d", &n);
  printf("%llu\n", pascal[n + 1][5] + pascal[n + 1][6] + pascal[n + 1][7]);
  return 0;
}