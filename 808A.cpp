// http://codeforces.com/contest/808/problem/A
// AC

#include <bits/stdc++.h>

using namespace std;

long power10(int n) {
  long ans = 1;
  for (int i = 1; i <= n; ++i) {
    ans *= 10;
  }
  return ans;
}

int main() {
  long n;
  scanf("%ld", &n);
  if (n < 10) {
    return !printf("1");
  }
  string s = to_string(n);
  int sz = s.size();
  long newn = (s[0] - '0' + 1) * power10(sz - 1);
  printf("%ld\n", newn - n);
  return 0;
}

