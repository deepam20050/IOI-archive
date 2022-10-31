// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/shil-and-lcp-pairsmonk/

#include <bits/stdc++.h>

using namespace std;

const int SZ = 2e6;
const int N = 1e6 + 5;

int trie[SZ][26];
long long cnt[SZ];
long long last[SZ];
long long ans[N];
queue < pair < int, int > > q;
string tmp;
int pos = 1;

inline void insert () {
  int node = 1;
  for (char ch : tmp) {
    int idx = ch - 'a';
    if (!trie[node][idx]) {
      trie[node][idx] = ++pos;
    }
    node = trie[node][idx];
    ++cnt[node];
  }
  ++last[node];
}

inline void bfs () {
  q.push({1, 0});
  while (!q.empty()) {
    int node = q.front().first;
    int idx = q.front().second;
    q.pop();
    long long res = 0;
    long long sum = 0;
    for (int i = 0; i < 26; ++i) {
      if (trie[node][i]) {
        sum += cnt[trie[node][i]];
      }
    }
    for (int i = 0; i < 26; ++i) {
      if (trie[node][i]) {
        long long sub = cnt[trie[node][i]];
        res += 1LL * (sum - sub) * sub;
        q.push({trie[node][i], idx + 1});
      }
    }
    ans[idx] += res >> 1LL;
    // cout << node << " " << idx << " " << cnt[node] << " " << sum << " " << last[node] << " " << ans[idx] << '\n';
    ans[idx] += (last[node] * (last[node] - 1) >> 1LL) + sum * last[node];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  int mx = 0;
  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    insert();
    mx = max(mx, (int)tmp.size());
  }
  bfs();
  for (int i = 0; i <= mx; ++i) {
    cout << ans[i] << " ";
  }
  return 0;
}