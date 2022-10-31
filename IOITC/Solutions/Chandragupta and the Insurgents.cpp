// AC

#include <cstdio>
#include <algorithm>
#include <utility>
#include <climits>

using namespace std;

const int N = 4e5 + 10;

pair < int , int > t[N];
int lzy[N];
int n, m, q;

pair < int, int > join (const pair < int, int > &a, const pair < int, int > &b) {
  if (a.first == b.first) {
    return {a.first, a.second + b.second};
  }
  if (a.first < b.first) {
    return a;
  }
  return b;
}

void push (int node, int l, int r) {
  if (!lzy[node]) {
    return;
  }
  t[node].first += lzy[node];
  if (l != r) {
    lzy[node << 1] += lzy[node];
    lzy[node << 1 | 1] += lzy[node];
  }
  lzy[node] = 0;
}

void build (int node, int l, int r) {
  lzy[node] = 0;
  if (l == r) {
    t[node] = {0, 1};
    return;
  }
  int m = l + r >> 1;
  build(node << 1, l, m);
  build(node << 1 | 1, m + 1, r);
  t[node] = join(t[node << 1], t[node << 1 | 1]);
}

void update (int node, int l, int r, int x, int y, int add) {
  push(node, l, r);
  if (l > y || r < x) {
    return;
  }
  if (x <= l && r <= y) {
    lzy[node] += add;
    push(node, l, r);
    return;
  }
  int m = l + r >> 1;
  update(node << 1, l, m, x, y, add);
  update(node << 1 | 1, m + 1, r, x, y, add);
  t[node] = join(t[node << 1], t[node << 1 | 1]);
}

pair < int, int > query (int node, int l, int r, int x, int y) {
  push(node, l, r);
  if (l > y || r < x) {
    return {INT_MAX >> 1, 0};
  }
  if (x <= l && r <= y) {
    return t[node];
  }
  int m = l + r >> 1;
  return join(query(node << 1, l, m, x, y), query(node << 1 | 1, m + 1, r, x, y));
}

int main() {
  scanf("%d %d %d", &n, &m, &q);
  build(1, 1, n);
  while (m--) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a > b) {
      swap(a, b);
    }
    update(1, 1, n, a, b - 1, 1);
  }
  while (q--) {
    int op, a, b;
    scanf("%d %d %d", &op, &a, &b);
    if (a > b) {
      swap(a, b);
    }
    if (!op) {
      update(1, 1, n, a, b - 1, 1);
    } else if (op == 1) {
      update(1, 1, n, a, b - 1, -1);
    } else {
      pair < int, int > res = query(1, 1, n, a, b - 1);
      printf("%d\n", res.first ? 0 : res.second);
    }
  }
  return 0;
}