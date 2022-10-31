// http://poj.org/problem?id=2389

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <cctype>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <vector>
#include <utility>

using namespace std;

string a, b;
int n1[50], n2[50], res[50 * 50];

int main() {
  cin >> a >> b;
  int n = a.size(), m = b.size();
  for (int i = 0; i < n; ++i) {
    n1[i] = a[i] - '0';
  }
  for (int i = 0; i < m; ++i) {
    n2[i] = b[i] - '0';
  }
  memset(res, -1, sizeof res);
  for (int i = n - 1; i >= 0; --i) {
    int carry = 0;
    int idx = n - i - 1;
    for (int j = m - 1; j >= 0; --j, ++idx) {
      int val = n2[j] * n1[i];
      if (res[idx] == -1) {
        res[idx] = val + carry;
        carry = res[idx] / 10;
        res[idx] %= 10;
      } else {
        res[idx] += val + carry;
        carry = res[idx] / 10;
        res[idx] %= 10;
      }
    }
    if (carry) {
      res[idx] = carry;
    }
  }
  int idx = 0;
  while (res[idx] != -1) {
    ++idx;
  }
  --idx;
  while (idx != -1) {
    printf("%d", res[idx]);
    --idx;
  }
  return 0;
}