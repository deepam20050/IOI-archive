// http://www.spoj.com/problems/ABA12C/
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 110, inf = 1e6;

long dp[N];
int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; ++i) {
      scanf("%d", a + i);
    } 
    dp[0] = 0;
    for (int i = 1; i < N; ++i) {
      dp[i] = inf;
    }
    for (int w = 1; w <= k; ++w) {
      for (int j = 1; j <= w; ++j) {
        if (a[j] != -1 && dp[w - j] != -1) {
          dp[w] = min(dp[w - j] + a[j], dp[w]);
        }        
      }
    }
    if (dp[k] == inf) {
      puts("-1");
    } else {
      printf("%ld\n", dp[k]);
    }
  }
  return 0;
}

