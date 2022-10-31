// http://codeforces.com/problemset/problem/368/B
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int cnt[N], a[N], query[N];

int main() {
  int n, m, distinct = 0;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    ++cnt[a[i]];
    if (cnt[a[i]] == 1) {
      ++distinct;
    }
  }
  query[0] = distinct;
  for (int i = 1; i < n; ++i) {
    --cnt[a[i - 1]];
    if (cnt[a[i - 1]] == 0) {
      --distinct;
    }
    query[i] = distinct;
  }
  while (m--) {
    int l;
    scanf("%d", &l);
    printf("%d\n", query[l - 1]);
  }
  return 0;
}