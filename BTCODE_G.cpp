// http://www.spoj.com/problems/BTCODE_G/
// Solved it on my own <3 !!

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int p[N], m[N], c[N];
bool used[N];
vector <int> g[N];

int find_set(int x) {
  return p[x] == x ? x : (p[x] = find_set(p[x]));
}

void dfs(int x) {
  used[x] = 1;
  for (int to : g[x]) {
    if (!used[to]) {
      m[to] = x;
      dfs(to);
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 0; i < n; ++i) {
    p[i] = i;
    m[i] = -1;
    c[i] = -1;
  }
  dfs(0);
  int q;
  scanf("%d", &q);
  while (q--) {
    int x, a, b;
    scanf("%d %d %d", &x, &a, &b);
    if (x == 1) {
      c[a] = b;
      if (m[a] != -1 && c[m[a]] == b) {
        p[a] = m[a];
      }
      for (int to : g[a]) {
        if (to != m[a] && c[to] == b) {
          p[to] = a;
        }
      }
    } else {
      puts(find_set(a) == find_set(b) ? "YES" : "NO");
    }
  }
  return 0;
}