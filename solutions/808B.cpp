// http://codeforces.com/contest/808/problem/B
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

long long sum[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    sum[i] = sum[i - 1] + x;
  }
  long long total = 0;
  for (int i = k; i <= n; ++i) {
    total += sum[i] - sum[i - k];
  }
  printf("%.10f", (double)total/(double)(n - k + 1));
  return 0;
}

