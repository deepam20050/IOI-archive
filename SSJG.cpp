// https://www.codechef.com/ICOP1904/problems/SSJG

#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int arr[N][N];

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n, m;
    scanf("%d %d", &n, &m);
    memset(arr, 0, sizeof arr);
    while (m--) {
      int x, y;
      scanf("%d %d", &x, &y);
      arr[x][y] = 1;
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
      }
    }
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        int sum1 = arr[i][j];
        int sum2 = arr[i][n] - arr[i][j];
        int sum3 = arr[n][j] - arr[i][j];
        int sum4 = arr[n][n] - sum1 - sum2 - sum3;
        mx = max(mx, min(sum1, min(sum2, min(sum3, sum4))));
      }
    }
    printf("%d\n", mx);
  }
  return 0;
}