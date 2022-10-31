#include <bits/stdc++.h>

using namespace std;

const int SZ = 3e6;
const int LN = 10;

int n;
int m;
int pos = 1;

struct data {
  vector < int > indices;
  int left = -1;
  int right = -1;
} trie[SZ];

inline void insert (int x, int idx) {
  int node = 1;
  for (int i = LN; i >= 0; --i) {
    bool b = x & (1 << i);
    if (b) {
      if (trie[node].right == -1) {
          trie[node].right = ++pos;
      }
      node = trie[node].right;
    } else {
      if (trie[node].left == -1) {
          trie[node].left = ++pos;
      }
      node = trie[node].left;
    }
    trie[node].indices.emplace_back(idx);
  }
}

int kthnum (int l, int r, int k) {
  int node = 1;
  int ret = 0;
  for (int i = LN; i >= 0; --i) {
    if (trie[node].left == -1) {
      node = trie[node].right;
      ret |= 1 << i;
      continue;
    }
    int x = lower_bound(trie[trie[node].left].indices.begin(), trie[trie[node].left].indices.end(), r + 1) - trie[trie[node].left].indices.begin();
    int y = lower_bound(trie[trie[node].left].indices.begin(), trie[trie[node].left].indices.end(), l) - trie[trie[node].left].indices.begin();
    int cnt = x - y;
    if (cnt >= k) {
      node = trie[node].left;
    } else {
      k -= cnt;
      node = trie[node].right;
      ret |= 1 << i;
    }
  }
  return ret;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1, x; i <= n; ++i) {
    scanf("%d", &x);
    insert(x, i);
  }
  while (m--) {
    int l, r, k;
    scanf("%d %d %d", &l, &r, &k);
    printf("%d\n", kthnum(l, r, k));
  }
  return 0;
}