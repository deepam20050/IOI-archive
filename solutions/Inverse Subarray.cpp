// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/inverse-subarray/

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

pair <int, int> arr[N];
int t[4 * N];

bool cmp (const pair <int, int> &a, const pair <int, int> &b) {
  if (a.first == b.first) {
    return a.second > b.second;
  }
  return a.first < b.first;
}

void update (int i, int l, int r, int idx, int val) {
  if (l == r) {
    t[i] = val;
    return;
  }
  int m = (l + r) >> 1;
  if (idx <= m) {
    update(i << 1, l, m, idx, val);
  } else {
    update(i << 1 | 1, m + 1, r, idx, val);
  }
  t[i] = max(t[i << 1], t[i << 1 | 1]);
}

int query (int i, int l, int r, int x, int y) {
  if (l > r) {
    return -2e9;
  }
  if (x <= l && r <= y) {
    return t[i];
  }
  int m = (l + r) >> 1;
  int ans = -2e9;
  if (x <= m) {
    ans = query(i << 1, l, m, x, y);
  }
  if (y > m) {
    ans = max(ans, query(i << 1 | 1, m + 1, r, x, y));
  }
  return ans;
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    fill(t, t + N + N + N + N, -2e9);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &arr[i].first);
      arr[i].second = i;
    }
    sort(arr, arr + n, cmp);
    int ans = 1;
    for (int i = 0; i < n; ++i) {
      int x = arr[i].first;
      int idx = arr[i].second;
      update(1, 0, n - 1, idx, idx);
      int r = query(1, 0, n - 1, idx + 1, n - 1);
      ans = max(ans, r - idx + 1);
    }
    printf("%d\n", ans);
  }
  return 0;
}