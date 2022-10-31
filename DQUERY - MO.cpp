// http://www.spoj.com/problems/DQUERY/

#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const int M = 2e5 + 5;
const int SZ = 1e6 + 5;
const int SQN = 223;

int arr[N];
int cnt[SZ];
int res[M];
int n;

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
    return (b.block == block) ? r < b.r : block < b.block;
  }
};
query Q[M];

inline void remove (int idx, int &ans) {
  --cnt[arr[idx]];
  ans -= !cnt[arr[idx]];
}

inline void add (int idx, int &ans) {
  ++cnt[arr[idx]];
  ans += cnt[arr[idx]] == 1;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", arr + i);
  }
  int q;
  scanf("%d", &q);
  for (int i = 1; i <= q; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    Q[i] = query(l, r, i);
  }
  sort(Q + 1, Q + q + 1);
  int mo_left = 1;
  int mo_right = 0;
  int ans = 0;
  for (int i = 1; i <= q; ++i) {
    int l = Q[i].l;
    int r = Q[i].r;
    while (mo_left < l) {
      remove(mo_left, ans);
      ++mo_left;
    }
    while (mo_left > l) {
      --mo_left;
      add(mo_left, ans);
    }
    while (mo_right < r) {
      ++mo_right;
      add(mo_right, ans);
    }
    while (mo_right > r) {
      remove(mo_right, ans);
      --mo_right;
    }
    res[Q[i].id] = ans;
  }
  for (int i = 1; i <= q; ++i) {
    printf("%d\n", res[i]);
  }
  return 0;
}