// http://codeforces.com/problemset/problem/301/D

#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

vector <int> v[N];
vector < pair <int, int> > qu[N];
int arr[N];
int pos[N];
long long ans[N];
long long bit[N];

int n;
int m;

void update (int idx) {
  while (idx <= n) {
    ++bit[idx];
    idx += idx & -idx;
  }
}

long long query (int idx) {
  long long res = 0;
  while (idx) {
    res += bit[idx];
    idx -= idx & -idx;
  }
  return res;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", arr + i);
    pos[arr[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = arr[i]; j <= n; j += arr[i]) {
      int l = min(i, pos[j]);
      int r = max(i, pos[j]);
      v[r].emplace_back(l);
    }
  }
  for (int i = 1; i <= m; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    qu[y].push_back({x, i});
  }
  for (int i = 1; i <= n; ++i) {
    for (int x : v[i]) {
      update(x);
    }
    long long curr = query(i);
    for (auto e : qu[i]) {
      ans[e.second] = curr - query(e.first - 1);
    }
  }
  for (int i = 1; i <= m; ++i) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}