// http://www.spoj.com/problems/ANARC08F/

#include <bits/stdc++.h>

using namespace std;

const int N = 1234;

unordered_map <string, int> mp;
long long dp[N][N];
string t[N];

int main() {
  int n, c, m, _ = 1;
  while (scanf("%d %d %d", &n, &c, &m)) {
    if (n == 0 && c == 0 && m == 0) {
      return 0;
    }
    mp.clear();
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (i == j) {
          dp[i][j] = 0;
        } else {
          dp[i][j] = 1LL << 40;
        }
      }
    }
    int newcity = 1;
    for (int i = 0; i <= c; ++i) {
      cin >> t[i];
      if (!mp[t[i]]) {
        mp[t[i]] = newcity++;
      }
    }
    while (m--) {
      string u, mid, to;
      cin >> u >> mid >> to;
      string tmp;
      for (char c : mid) {
        if ('0' <= c && c <= '9') {
          tmp += c;
        }
      }
      long long w = stoll(tmp);
      int s = mp[u];
      int e = mp[to];
      if (!s) {
        mp[u] = s = newcity++;
      }
      if (!e) {
        mp[to] = e = newcity++;
      }
      if (mid.front() == '<' && mid.back() == '>') {
        dp[s][e] = min(dp[s][e], w);
        dp[e][s] = min(dp[e][s], w);
      } else if (mid.front() == '<') {
        dp[e][s] = min(dp[e][s], w);
      } else {
        dp[s][e] = min(dp[s][e], w);
      }
    }
    for (int k = 1; k < newcity; ++k) {
      for (int i = 1; i < newcity; ++i) {
        for (int j = 1; j < newcity; ++j) {
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
      }
    }
    long long ans = 0;
    for (int i = 1; i <= c; ++i) {
      ans += dp[mp[t[0]]][mp[t[i]]] + dp[mp[t[i]]][mp[t[0]]];
    }
    printf("%d. %lld\n", _++, ans);
  }
  return 0;
}