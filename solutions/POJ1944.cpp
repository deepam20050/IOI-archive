// http://acm.tzc.edu.cn/acmhome/problemdetail.do?&method=showdetail&id=1550

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

const int N = 12345;

int x[N], y[N], b[N];

int main() {
  int n, p;
  scanf("%d %d", &n, &p);
  for (int i = 0; i < p; ++i) {
    scanf("%d %d", x + i, y + i);
    --x[i];
    --y[i];
  }
  int res = 1 << 30;
  for (int i = 0; i < n; ++i) {
    memset(b, 0, sizeof b);
    for (int j = 0; j < p; ++j) {
      int l = x[j] >= i ? x[j] : x[j] + n;
      int r = y[j] >= i ? y[j] : y[j] + n;
      if (l > r) {
        swap(l, r);
      }
      ++b[l];
      --b[r];
    }
    int ans = 0;
    for (int j = 0, sum = 0; j < n; ++j) {
      sum += b[i + j];
      if (sum > 0) {
        ++ans;
      }
    }
    res = min(res, ans);
  }
  printf("%d\n", res);
  return 0;
}