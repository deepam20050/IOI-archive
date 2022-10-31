// http://codeforces.com/contest/961/problem/E
// Clever solution - http://codeforces.com/blog/entry/58743?#comment-423754

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;

vector <int> bit[N];
int arr[N];
int n;

void add (int val, int idx) {
  while (idx <= n) {
    bit[idx].emplace_back(val);
    idx += idx & -idx;
  }
}

long long query (int idx, int val) {
  long long sum = 0;
  while (idx) {
    int pos = lower_bound(bit[idx].begin(), bit[idx].end(), val) - bit[idx].begin();
    sum += bit[idx].size() - pos;   
    idx -= idx & -idx;
  }
  return sum;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", arr + i);
    add(arr[i], i);
  }
  for (int i = 1; i <= n; ++i) {
    sort(bit[i].begin(), bit[i].end());
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (arr[i] <= i) {
      continue;
    }
    ans += query(min(n, arr[i]), i) - query(i, i);
  }
  printf("%lld\n", ans);
  return 0;
}