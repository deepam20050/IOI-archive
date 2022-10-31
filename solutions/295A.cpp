// http://codeforces.com/problemset/problem/295/A

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

long long arr[N];
long long d[N];
long long sum[N];
int l[N];
int r[N];
int inp[N];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", arr + i);
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d %lld", l + i, r + i, d + i);
    ++r[i];
  }
  while (k--) {
    int x, y;
    scanf("%d %d", &x, &y);
    ++inp[x];
    --inp[y + 1];
  }
  for (int i = 1; i <= m; ++i) {
    inp[i] += inp[i - 1];
    sum[l[i]] += d[i] * inp[i];
    sum[r[i]] -= d[i] * inp[i];
  }
  for (int i = 1; i <= n; ++i) {
    sum[i] += sum[i - 1];
    arr[i] += sum[i];
    printf("%lld ", arr[i]);
  }
  return 0;
}