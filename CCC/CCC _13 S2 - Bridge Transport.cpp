// https://dmoj.ca/problem/ccc13s2

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

const int N = 100010;

int a[N];

int main() {
  int w, n;
  scanf("%d %d", &w, &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  int sum = 0, cars = 0;
  for (int i = 1; i <= n; ++i) {
    if (i <= 4) {
      sum += a[i];
    } else {
      sum -= a[i - 4];
      sum += a[i];
    }
    if (sum <= w) {
      cars = i;
    } else {
      break;
    }
  }
  printf("%d\n", cars);
  return 0;
}