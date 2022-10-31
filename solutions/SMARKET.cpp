// https://www.codechef.com/problems/SMARKET

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int bit[N];
int lft[N];
int rgt[N];
int ar[N];
int prv[N];
int nxt[N];
int ans[N];
pair <int, int> off[N];
pair <int, int> p[N];

int n;
int q;

void update (int idx) {
  while (idx <= n) {
    ++bit[idx];
    idx += idx & -idx;
  }
}

int query(int idx) {
  int res = 0;
  while (idx) {
    res += bit[idx];
    idx -= idx & -idx;
  }
  return res;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", ar + i);
    }
    nxt[n] = n;
    for (int i = n - 1; i >= 1; --i) {
      if (ar[i] == ar[i + 1]) {
        nxt[i] = nxt[i + 1];
      } else {
        nxt[i] = i;
      }
    }
    prv[1] = 1;
    for (int i = 2; i <= n; ++i) {
      if (ar[i] == ar[i - 1]) {
        prv[i] = prv[i - 1];
      } else {
        prv[i] = i;
      }
    }
    for (int i = 1; i <= q; ++i) {
      scanf("%d %d %d", lft + i, rgt + i, &p[i].first);
      p[i].second = i;
    }
    sort(p + 1, p + q + 1);
    int pos = 0;
    for (int i = 1; i <= n; ++i) {
      if (prv[i] == i) {
        off[++pos] = {nxt[i] - i + 1, i};
      }
    }
    sort(off + 1, off + pos + 1);
    memset(bit, 0, sizeof bit);
    for (int i = q; i >= 1; --i) {
      int idx = p[i].second;
      int l = lft[idx];
      int r = rgt[idx];
      int k = p[i].first;
      if (nxt[l] >= r) {
        ans[idx] = (r - l + 1) >= k;
      } else {
        while (off[pos].first >= k) {
          update(off[pos].second);
          --pos;
        }
        ans[idx] = query(prv[r] - 1) - query(nxt[l]) + ((r - prv[r] + 1) >= k) + ((nxt[l] - l + 1) >= k);
      }
    }
    for (int i = 1; i <= q; ++i) {
      printf("%d\n", ans[i]);
    }
  } 
  return 0;
}