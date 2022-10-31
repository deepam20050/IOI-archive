// http://www.spoj.com/problems/KQUERY/

#include <bits/stdc++.h>

using namespace std;
using pi = pair <int, int>;

const int N = 200010;

int x[N];
int y[N];
int res[N];
int bit[N];
vector <pi> v;

int n;

void update(int idx) {
  while (idx <= n) {
    ++bit[idx];
    idx |= idx + 1;
  }
}

int query(int idx) {
  int sum = 0;
  while (idx > 0) {
    sum += bit[idx];
    idx = (idx & (idx + 1)) - 1;
  }
  return sum;
}

int main() {
  scanf("%d", &n);
  for (int i = 1, x; i <= n; ++i) {
    scanf("%d", &x);
    v.push_back({x, -i});
  }
  int q;
  scanf("%d", &q);
  for (int i = 0, z; i < q; ++i) {
    scanf("%d %d %d", x + i, y + i, &z);
    v.push_back({z, i});
  }
  sort(v.begin(), v.end(), greater <pi> ());
  for (const auto &e : v) {
    int a = e.first;
    int b = e.second;
    if (b >= 0) {
      res[b] = query(y[b]) - query(x[b] - 1);
    } else {
      update(-b);
    }
  }
  for (int i = 0; i < q; ++i) {
    printf("%d\n", res[i]);
  }
  return 0;
}