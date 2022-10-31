// http://acm.timus.ru/problem.aspx?space=1&num=1146

#include <bits/stdc++.h>

using namespace std;

const int N = 122;

int a[N][N];
int sum[N][N];
pair <int, int> best[N][N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      scanf("%d", a[i] + j);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    }
  }
  int mx = -2e9;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = j; k >= 1; --k) {
        int at = best[j][k].first;
        mx = max(mx, sum[i][j] - sum[i][k - 1] - sum[at][j] + sum[at][k - 1]);
      }
      for (int k = j; k >= 1; --k) {
        if (sum[i][j] - sum[i][k - 1] < best[j][k].second) {
          best[j][k].second = sum[i][j] - sum[i][k - 1];
          best[j][k].first = i;
        }
      }
    }
  }
  printf("%d", mx);
  return 0;
}