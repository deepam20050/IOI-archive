// https://www.codechef.com/problems/UNIONSET
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 2501;

bool sets[N][N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    memset(sets, 0, sizeof sets);   
    for (int i = 0; i < n; ++i) {
      int sz;
      scanf("%d", &sz);
      while (sz--) {
        int x;
        scanf("%d", &x);
        sets[i][x] = 1;
      }  
    }
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
      for (int j = i + 1; j < n; ++j) {
        bool flag = 1;
         for (int x = 1; x <= k; ++x) {
           if (!(sets[i][x] || sets[j][x])) {
             flag = 0;
             break;
           }
         }
       ans += flag;
      }
     }
    printf("%d\n", ans);
  }
  return 0;
}
