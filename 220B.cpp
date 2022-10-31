// http://codeforces.com/contest/220/problem/B

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int SQN = 320;

int arr[N];
int cnt[N];
int print[N];
int ans;
int n;
int q;

struct query {
  int l;
  int r;
  int id;
  int block;
  query () { }
  query (int _l, int _r, int _id) {
    l = _l;
    r = _r;
    id = _id;
    block = _l / SQN;
  }
  bool operator < (const query &b) const {
    return b.block == block ? r < b.r : block < b.block;
  }
} Q[N];

inline void add (int idx) {
  if (arr[idx] > n) {
    return;
  }
  ans -= arr[idx] == cnt[arr[idx]];
  ++cnt[arr[idx]];
  ans += cnt[arr[idx]] == arr[idx];
}

inline void remove (int idx) {
  if (arr[idx] > n) {
    return;
  }
  ans -= cnt[arr[idx]] == arr[idx];
  --cnt[arr[idx]];
  ans += cnt[arr[idx]] == arr[idx];
}

int main() {
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", arr + i);
  }
  for (int i = 0; i < q; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    Q[i] = query(l, r, i);
  }
  sort(Q, Q + q);
  int mo_left = 1;
  int mo_right = 0;
  for (int i = 0; i < q; ++i) {
    int l = Q[i].l;
    int r = Q[i].r;
    while (mo_left < l) {
      remove(mo_left);
      ++mo_left;
    }
    while (mo_right < r) {
      ++mo_right;
      add(mo_right);
    }
    while (mo_left > l) {
      --mo_left;
      add(mo_left);
    }
    while (mo_right > r) {
      remove(mo_right);
      --mo_right;
    }
    print[Q[i].id] = ans;
  }
  for (int i = 0; i < q; ++i) {
    printf("%d\n", print[i]);
  }
  return 0;
}