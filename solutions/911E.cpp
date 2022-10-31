// http://codeforces.com/contest/911/problem/E

#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int a[N];
stack <int> s;

int n;
int k;

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < k; ++i) {
    scanf("%d", a + i);
  }
  int curr = 1;
  for (int i = 0; i < k; ++i) {
    while (!s.empty() && s.top() == curr) {
      s.pop();
      ++curr;
    }
    if (!s.empty() && s.top() < a[i]) {
      return !printf("-1");
    }
    s.push(a[i]);
  }
  while (!s.empty() && s.top() == curr) {
    s.pop();
    ++curr;
  }
  if (s.empty()) {
    for (int i = n - 1; i >= k; --i, ++curr) {
      a[i] = curr;
    }
    for (int i = 0; i < n; ++i) {
      printf("%d ", a[i]);
    }
    return 0;
  }
  for (int i = k; i < n; ++i) {
    while (!s.empty() && s.top() == curr) {
      s.pop();
      ++curr;
    }
    if (s.empty()) {
      for (int j = n - 1; j >= i; --j) {
        a[j] = curr++;
      }
      break;
    }
    int x = s.top() - 1;
    while (x >= curr) {
      a[i++] = x--;
    }
    curr = s.top() + 1;
    s.pop();
    --i;
  }
  for (int i = 0; i < n; ++i) {
    printf("%d ", a[i]);
  }
  return 0;
}