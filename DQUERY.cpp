// http://www.spoj.com/problems/DQUERY/

#include <bits/stdc++.h>

using namespace std;

const int N = 30010;
const int M = 1e6 + 1;

int bit[M];
int arr[N];
int prv[M];
int res[200010];
pair <int, pair <int, int>> inp[200010];

int n;

void update (int idx, int val) {
  while (idx <= n) {
    bit[idx] += val;
    idx += idx & -idx;
  }
}

int query (int idx) {
  int sum = 0;
  while (idx) {
    sum += bit[idx];
    idx -= idx & -idx;
  }
  return sum;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", arr + i);
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    scanf("%d %d", &inp[i].second.first, &inp[i].first);
    inp[i].second.second = i;
  }
  sort(inp, inp + q);
  memset(prv, -1, sizeof prv);
  int idx = 0;
  for (int i = 1; i <= n; ++i) {
    if (prv[arr[i]] != -1) {
      update(prv[arr[i]], -1);
    }
    prv[arr[i]] = i;
    update(i, 1);
    while (idx < q && inp[idx].first == i) {
      res[inp[idx].second.second] = query(i) - query(inp[idx].second.first - 1);
      ++idx;
    }
  }
  for (int i = 0; i < q; ++i) {
    printf("%d\n", res[i]);
  }
  return 0;
}