// http://codeforces.com/problemset/problem/407/B
// Look at the comment of graceoflives for explanation - http://codeforces.com/problemset/problem/407/B

#include <bits/stdc++.h>

using namespace std;

const int N = 1010, mod = 1e9 + 7;

int a[N], dp[N];

int main() {
	int n;
	scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  dp[1] = 2; 
  for (int i = 2; i <= n; ++i) {
    dp[i] = 2;
    for (int j = a[i]; j < i; ++j) {
      dp[i] = (dp[i] + dp[j]) % mod;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = (ans + dp[i]) % mod;
  }
  printf("%d", ans);
	return 0;
}
