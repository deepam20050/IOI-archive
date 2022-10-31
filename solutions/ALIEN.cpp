// http://www.spoj.com/problems/ALIEN/
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int sum[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
   int n;
   long m;
   scanf("%d %ld", &n, &m);
   for (int i = 1; i <= n; ++i) {
    int foo;
    scanf("%d", &foo);
    sum[i] = sum[i - 1] + foo;
   }  
   int j = 1, station = -1, ppl = 0;
   for (int i = 1; i <= n; ++i) {
     while (j <= n && sum[j] - sum[i - 1] <= m) {
       ++j;
     }
     if (j - i > station) {
       station = j - i;
       ppl = sum[j - 1] - sum[i - 1];
     } else if (j - i == station && sum[j - 1] - sum[i - 1] < ppl) {
       ppl = sum[j - 1] - sum[i - 1];
     }
   }
   printf("%d %d\n",ppl, station);
  } 
  return 0;
}
