// https://www.codechef.com/problems/ANUGCD

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

vector <int> prime[N];
vector <int> v[N];

int mx;
int n;
int m;

struct node {
  int val;
  node *lft;
  node *rgt;
  node () {
    val = -1;
    lft = nullptr;
    rgt = nullptr; 
  }
  node* update (int l, int r, int idx, int x) {
    val = max(val, x);
    if (l < r) {
      int m = (l + r) >> 1;
      if (idx <= m) {
        if (lft == nullptr) {
          lft = new node();
        }
        lft = lft->update(l, m, idx, x);
      } else {
        if (rgt == nullptr) {
          rgt = new node();
        }
        rgt = rgt->update(m + 1, r, idx, x);
      }
    }
    return this;
  }
  void query (int l, int r, int x, int y) {
    if (x <= l && r <= y) {
      mx = max(mx, val);
      return;
    }
    int m = (l + r) >> 1;
    if (x <= m && lft != nullptr) {
      lft->query(l, m, x, y);
    } 
    if (y > m && rgt != nullptr) {
      rgt->query(m + 1, r, x, y);
    }
  }
};

node *tree[N];

int main() { 
  for (int i = 2; i < N; ++i) {
    if (prime[i].empty()) {
      for (int j = i; j < N; j += i) {
        prime[j].emplace_back(i);
      }
    }
  }
  for (int i = 2; i < N; ++i) {
    tree[i] = new node();
  }
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    v[x].emplace_back(i);
    for (int p : prime[x]) {
      tree[p] = tree[p]->update(1, n, i, x);
    }
  }
  while (m--) {
    int g, l, r;
    scanf("%d %d %d", &g, &l, &r);
    mx = -1;
    for (int x : prime[g]) {
      tree[x]->query(1, n, l, r);
    }
    if (mx == -1) {
      puts("-1 -1");
      continue;
    }
    int times = upper_bound(v[mx].begin(), v[mx].end(), r) - lower_bound(v[mx].begin(), v[mx].end(), l);
    printf("%d %d\n", mx, times);
  }
  return 0;
}