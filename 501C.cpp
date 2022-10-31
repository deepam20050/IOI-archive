// http://codeforces.com/contest/501/problem/C
// Really good problem

#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 17;

int d[N], s[N];
queue <int> q;
vector < pair <int, int> > v;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", d + i, s + i);
    if (d[i] == 1) {
      q.push(i);
    }
  }
  while (!q.empty()) {
    int from = q.front();
    q.pop();
    if (!d[from]) {
      continue;
    }
    --d[from];
    int to = s[from];
    s[from] = 0;
    --d[to];
    s[to] ^= from;
    v.push_back({from, to});
    if (d[to] == 1) {
      q.push(to);
    }
  }
  printf("%d\n", (int)v.size());
  for (auto &e : v) {
    printf("%d %d\n", e.first, e.second);
  }
  return 0;
}