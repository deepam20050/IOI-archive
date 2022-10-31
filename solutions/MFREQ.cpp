// https://www.codechef.com/problems/MFREQ
// Carefully analyze the constraints

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N], s[N], e[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  s[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (a[i] == a[i - 1]) {
      s[i] = s[i - 1];
    } else {
      s[i] = i;
    }
  }
  e[n] = n;
  for (int i = n - 1; i >= 1; --i) {
    if (a[i] == a[i + 1]) {
      e[i] = e[i + 1];
    } else {
      e[i] = i;
    }
  }
  while (m--) {
   int l, r, k;
   scanf("%d %d %d", &l, &r, &k);
   int idx = (l + r) >> 1;
   if (min(r, e[idx]) - max(l, s[idx]) + 1 >= k) {
   		printf("%d\n", a[idx]);
   } else {
   	puts("-1");
   }
  }
	return 0;
}