// http://poj.org/problem?id=2388

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

const int N = 10010;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  printf("%d\n", a[n >> 1]);
  return 0;
}