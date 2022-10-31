// https://www.codechef.com/problems/PARTCNT
// Nice problem

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const long long mod = 1e9 + 7;

int a[N];
int best[N];
long long dp[N];
long long pref[N];
unordered_map <int, int> cnt;

int n, k;

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  int j = 1;
  int curr = 0;
  for (int i = 1; i <= n; ++i) {
    if (!cnt[a[i]]) {
      ++curr;
    }
    ++cnt[a[i]];
    while (curr > k) {
      --cnt[a[j]];
      if (!cnt[a[j]]) {
        --curr;
      }
      ++j;
    }
    best[i] = j;
  }
  pref[0] = 1LL;
  dp[0] = 1LL;
  for (int i = 1; i <= n; ++i) {
    dp[i] = pref[i - 1];
    if (best[i] - 1 > 0) {
      dp[i] -= pref[best[i] - 2];
    }
    dp[i] += mod;
    dp[i] %= mod;
    pref[i] += dp[i] + pref[i - 1];
    pref[i] += mod;
    pref[i] %= mod;
  }
  printf("%lld", dp[n]);
  return 0;
}