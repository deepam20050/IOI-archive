// https://www.codechef.com/INOIPRAC/problems/INOI1502 

#include <bits/stdc++.h>

using namespace std;

const int N = 150010;

int pw[N];
int ans[N];

int n, m;

void mod(int &x) {
  x = (x % m + m) % m;
}

int main() {
  scanf("%d %d", &n, &m);
  pw[0] = 1;
  for (int i = 1; i <= n; ++i) {
    pw[i] = pw[i - 1] << 1;
    mod(pw[i]);
    ans[i] = pw[i];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + i; j <= n; j += i) {
      ans[j] -= ans[i];
      mod(ans[j]);
    }
  }
  printf("%d\n", ans[n]);
  return 0;
}