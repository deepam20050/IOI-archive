// http://www.spoj.com/problems/SUBXOR/

#include <bits/stdc++.h>

using namespace std;

const int N = 3e6;
const int LN = 20;

int trie[N][2];
int cnt[N];
int pref;
int pos;
int k;
int n;
int tc;

void insert () {
  int node = 1;
  for (int i = LN; i >= 0; --i) {
    bool b = pref & (1 << i);
    if (!trie[node][b]) {
      trie[node][b] = ++pos;
    }
    node = trie[node][b];
    ++cnt[node];
  }
}

long long query () {
  int node = 1;
  long long ret = 0;
  for (int i = LN; i >= 0; --i) {
    bool b1 = pref & (1 << i);
    bool b2 = k & (1 << i);
    if (b2) {
      if (!b1) {
        ret += cnt[trie[node][0]] * 1LL;
        node = trie[node][1];
      } else {
        ret += cnt[trie[node][1]] * 1LL;
        node = trie[node][0];
      }
    } else {
      if (b1) {
        node = trie[node][1];
      } else {
        node = trie[node][0];
      }
    }
  }
  return ret;
}

int main() {
  scanf("%d", &tc);
  while (tc--) {
    memset(trie, 0, sizeof trie);
    memset(cnt, 0, sizeof cnt);
    pos = 1;
    scanf("%d %d", &n, &k);
    pref = 0;
    insert();
    long long ans = 0;
    for (int i = 0, x; i < n; ++i) {
      scanf("%d", &x);
      pref ^= x;
      ans += query();
      insert();
    }
    printf("%lld\n", ans);
  }
  return 0;
}