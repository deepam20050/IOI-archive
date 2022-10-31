// https://www.codechef.com/problems/GCDCNT

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
const int M = 5e4 + 1;

struct node {
  int sum;
  node *lft;
  node *rgt;
  node () {
    sum = 0;
    lft = nullptr;
    rgt = nullptr;
  }
  node* update (int l, int r, int idx, int x) {
    sum += x;
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
  int query (int l, int r, int x, int y) {
    if (x <= l && r <= y) {
      return sum;
    }
    int m = (l + r) >> 1;
    int res = 0;
    if (x <= m && lft != nullptr) {
      res += lft->query(l, m, x, y);
    } 
    if (y > m && rgt != nullptr) {
      res += rgt->query(m + 1, r, x, y);
    }
    return res;
  }
};

node *t[N];
int arr[M];
vector <int> primes[N];

void update (int add, int idx, int pos) {
  int sz = 1 << primes[idx].size();
  for (int mask = 1; mask < sz; ++mask) {
    int mul = 1;
    for (int i = 0; i < primes[idx].size(); ++i) {
      if (mask & 1 << i) {
        mul *= primes[idx][i];
      }
    }
    t[mul] = t[mul]->update(1, M, pos, add);
  }
}

int main() {
  for (int i = 2; i < N; ++i) {
    if (primes[i].empty()) {
      for (int j = i; j < N; j += i) {
        primes[j].emplace_back(i);
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    t[i] = new node();
  }
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", arr + i);
    update(1, arr[i], i);
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int x, y;
      scanf("%d %d", &x, &y);
      update(-1, arr[x], x);
      arr[x] = y;
      update(1, arr[x], x);
    } else {
      int l, r, g;
      scanf("%d %d %d", &l, &r, &g);
      int sz = 1 << primes[g].size();
      int sum = 0;
      for (int mask = 1; mask < sz; ++mask) {
        int bits = 0;
        int mul = 1;
        for (int i = 0; i < primes[g].size(); ++i) {
          if (mask & 1 << i) {
            ++bits;
            mul *= primes[g][i];
          }
        }
        int cnt = t[mul]->query(1, M, l, r);
        if (bits & 1) {
          sum += cnt;
        } else {
          sum -= cnt;
        }
      }
      printf("%d\n", r - l + 1 - sum);
    }
  }
  return 0;
}