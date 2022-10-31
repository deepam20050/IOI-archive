// http://www.spoj.com/problems/HOTELS/
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

long sum[N];

int main() {
  int n;
  long m;
  scanf("%d %ld", &n, &m);
  for (int i = 1; i <= n; ++i) {
    int foo;
    scanf("%d", &foo);
    sum[i] = sum[i - 1] + foo;
  }
  int j = 0;
  long ans = -1;
  for (int i = 1; i <= n; ++i) {
    while (j <= n && sum[j] - sum[i - 1] <= m) {
      ++j;
    }  
    ans = max(ans, sum[j - 1] - sum[i - 1]);
  }
  printf("%ld\n", ans);
}
