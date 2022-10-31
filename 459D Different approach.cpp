// http://codeforces.com/contest/459/problem/D

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 1;

int arr[N];
int val[N];
int bit[N];
unordered_map <int, int> cnt;
int n;

int query (int idx) {
  int res = 0;
  while (idx) {
    res += bit[idx];
    idx -= idx & -idx;
  }
  return res;
}

void update (int idx) {
  while (idx <= n) {
    ++bit[idx];
    idx += idx & -idx;
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", arr + i);
    ++cnt[arr[i]];
    val[i] = cnt[arr[i]];
  }
  cnt.clear();
  long long ans = 0;
  for (int i = n; i >= 1; --i) {
    ans += query(val[i] - 1);
    ++cnt[arr[i]];
    update(cnt[arr[i]]);
  }
  printf("%lld", ans);
  return 0;
}