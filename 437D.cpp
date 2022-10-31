// http://codeforces.com/problemset/problem/437/D

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int arr[N];
int size[N];
int pr[N];
vector < pair < int, pair < int, int > > > v;
int n;
int m;

bool cmp (const pair < int, pair < int, int > > &a, const pair < int, pair < int, int > > &b) {
  return a.first > b.first;
}

int find_parent (int x) {
  return pr[x] == x ? x : pr[x] = find_parent(pr[x]);
}

long long join (int x, int y) {
  x = find_parent(x);
  y = find_parent(y);
  if (x == y) {
    return 0;
  }
  if (size[x] < size[y]) {
    swap(x, y);
  }
  long long ret = 1LL * size[x] * size[y];
  size[x] += size[y];
  pr[y] = x;
  return ret;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", arr + i);
    size[i] = 1;
    pr[i] = i;
  }
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    v.push_back({min(arr[x], arr[y]), {x, y}});
  }
  sort(v.begin(), v.end(), cmp);
  double ans = 0;
  for (auto &e : v) {
    ans += join(e.second.first, e.second.second) * e.first;
  }
  printf("%lf\n", ans / ((n * (n - 1.0)) / 2.0));
  return 0;
}