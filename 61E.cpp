// http://codeforces.com/contest/61/problem/E

#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

long long bit[4][N];
pair <int, int> arr[N];

int n;

void update (int who, int idx, long long add) {
  while (idx <= n) {
    bit[who][idx] += add;
    idx += idx & -idx;
  }
}

long long query (int who, int idx) {
  long long res = 0;
  while (idx) {
    res += bit[who][idx];
    idx -= idx & -idx;
  }
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &arr[i].first);
    arr[i].second = i;
  }
  sort(arr + 1, arr + n + 1);
  for (int i = 1; i <= n; ++i) {
    int idx = arr[i].second;
    update(1, idx, 1LL);
    update(2, idx, query(1, n) - query(1, idx));
    update(3, idx, query(2, n) - query(2, idx));
  }
  printf("%lld", query(3, n));
  return 0;
}