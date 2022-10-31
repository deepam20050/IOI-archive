// http://codeforces.com/contest/777/problem/B
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

char s[N], ss[N];

int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  scanf("%s", ss);
  sort(s, s + n);
  sort(ss, ss + n);
  int j = n - 1;
  for (int i = n - 1; i >= 0; --i) {
    if (ss[j] >= s[i]) {
      --j;
    }
  }
  printf("%d\n", j + 1);
  j = 0;
  for (int i = 0; i < n; ++i) {
    if (ss[i] > s[j]) {
      ++j;
    }
  }
  printf("%d\n", j);
  return 0;
}

