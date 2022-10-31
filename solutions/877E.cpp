// http://codeforces.com/contest/877/problem/E

#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

struct node {
  int on, lazy;
};

vector <int> a, g[N];
node t[4 * N];
bool used[N];
int c[N];
int s[N], e[N];

void dfs(int x) {
  a.emplace_back(x);
  s[x] = a.size() - 1;
  used[x] = 1;
  for (int to : g[x]) {
    if (!used[to]) {
      dfs(to);
    }
  }
  a.emplace_back(x);
  e[x] = a.size() - 1;
}

void join(int p, int i, int j) {
  t[p].on = t[i].on + t[j].on;
  t[p].lazy = 0;
}

void propagate(int i, int l, int r) {
  if (t[i].lazy) {
    int total = r - l + 1;
    t[i].on = total - t[i].on;
    if (l < r) {
      t[i << 1].lazy ^= 1;
      t[i << 1 | 1].lazy ^= 1;
    }
    t[i].lazy = 0;
  }
}

void build(int i, int l, int r) {
  if (l == r) {
    t[i].on = c[a[l]];
    t[i].lazy = 0;
    return;
  }
  int mid = (l + r) >> 1;
  build(i << 1, l, mid);
  build(i << 1 | 1, mid + 1, r);
  join(i, i << 1, i << 1 | 1);
}

void update(int i, int l, int r, int x, int y) {
  propagate(i, l, r);
  if (x <= l && r <= y) {
    t[i].lazy = 1;
  } else {
    int mid = (l + r) >> 1;
    if (x <= mid) {
      update(i << 1, l, mid, x, y);
    }
    if (y > mid) {
      update(i << 1 | 1, mid + 1, r, x, y);
    }
    propagate(i << 1, l, mid);
    propagate(i << 1 | 1, mid + 1, r);
    join(i, i << 1, i << 1 | 1);
  }
}

int query(int i, int l, int r, int x, int y) {
  propagate(i, l, r);
  if (x <= l && r <= y) {
    return t[i].on;
  }
  int mid = (l + r) >> 1, ans = 0;
  if (x <= mid) {
    ans += query(i << 1, l, mid, x, y);
  }
  if (y > mid) {
    ans += query(i << 1 | 1, mid + 1, r, x, y);
  }
  return ans;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 2; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    g[x].emplace_back(i);
    g[i].emplace_back(x);
  }
  dfs(1);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", c + i);
  }
  const int m = a.size();
  build(1, 0, m - 1);
  int q;
  scanf("%d", &q);
  while (q--) {
    string temp;
    int v;
    cin >> temp >> v;
    if (temp[0] == 'g') {
      printf("%d\n", query(1, 0, m - 1, s[v], e[v]) >> 1);
    } else {
      update(1, 0, m - 1, s[v], e[v]);
    }
  }
  return 0;
}