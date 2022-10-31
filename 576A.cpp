// http://codeforces.com/problemset/problem/576/A

#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 1;

vector <int> primes[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 2; i <= n; ++i) {
    if (primes[i].empty()) {
      for (int j = i; j <= n; j += i) {
        primes[j].emplace_back(i);
      }
    }
  }
  vector <int> v;
  for (int i = 2; i <= n; ++i) {
    if (primes[i].size() == 1) {
      v.emplace_back(i);
    }
  }
  printf("%d\n", (int)v.size());
  for (int x : v) {
    printf("%d ", x);
  }
  return 0;
}