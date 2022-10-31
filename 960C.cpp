// http://codeforces.com/contest/960/problem/C

#include <bits/stdc++.h>

using namespace std;

int pw[30];

int main() {
  int x, d;
  scanf("%d %d", &x, &d);
  for (int i = 0; i <= 29; ++i) {
    pw[i] = 1 << i;
  }
  vector <int> v;
  int sum = 0;
  while (x) {
    int need = 0;
    for (int i = 29; i >= 0; --i) {
      if (pw[i] - 1 <= x) {
        need = i;
        x -= pw[i] - 1;
        break;
      }
    }
    sum += need;
    v.push_back(need);
  }
  printf("%d\n", sum);
  long long curr = 1;
  for (int x : v) {
    int tmp = x;
    while (tmp--) {
      printf("%lld ", curr);
    }
    curr += d;
  }
  return 0;
}