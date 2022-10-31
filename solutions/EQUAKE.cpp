#include <bits/stdc++.h>

using namespace std;

const int N = 8e5;

struct data {
  int need;
  int ans;
  int mx[12];
  data () {
    need = 0;
    ans = 0;
    memset(mx, 0, sizeof mx);
  }
};

data t[4 * N];
string str[N];
int n, q;

void push (int node, int l, int r) {
  if (t[node].need >= 0) {
    t[node].ans = t[node].mx[t[node].need];
    if (l < r) {
      t[node << 1].need = t[node].need;
      t[node << 1 | 1].need = t[node].need;
    }
  }
}

void build (int node, int l, int r) {
  if (l != r) {
    int m = l + r >> 1;
    build(node << 1, l, m);
    build(node << 1 | 1, m + 1, r);
    for (int i = 0; i < 5; ++i) {
      t[node].mx[i] = max(t[node << 1].mx[i], t[node << 1 | 1].mx[i]);
    }
    t[node].ans = t[node].mx[0];
    t[node].need = 0;
    return;
  }
  const int sz = str[l].size();
  for (int i = 0; i < sz; ++i) {
    int mul = 1;
    for (int j = i - 1; j >= 0; --j, mul *= 10) {
      t[node].mx[i] += (str[l][j] - '0') * mul;
    }
    for (int j = sz - 1; j >= i; --j, mul *= 10) {
      t[node].mx[i] += (str[l][j] - '0') * mul;
    }
  }
  for (int i = sz; i < 12; ++i) {
    t[node].mx[i] = t[node].mx[i % sz];
  }
}

void update (int node, int l, int r, int x, int y, int val) {
  push(node, l, r);
  if (x <= l && r <= y) {
    t[node].need = (t[node].need == -1 ? 0 : t[node].need);
    t[node].need += val;
    t[node].need %= 12;
    t[node].ans = t[node].mx[t[node].need];
    return;
  }
  int m = l + r >> 1;
  if (x <= m) {
    update(node << 1, l, m, x, y, val);
  }
  if (y > m) {
    update(node << 1 | 1, m + 1, r, x, y, val);
  }
  push(node << 1, l, m);
  push(node << 1 | 1, m + 1, r);
  t[node].ans = max(t[node << 1].ans, t[node << 1 | 1].ans);
  t[node].need = -1;
}

int query (int node, int l, int r, int x, int y) {
  push(node, l, r);
  if (x <= l && r <= y) {
    return t[node].ans;
  }
  int m = l + r >> 1;
  int mx = -1;
  if (x <= m) {
    mx = query(node << 1, l, m, x, y);
  }
  if (y > m) {
    mx = max(mx, query(node << 1 | 1, m + 1, r, x, y));
  }
  return mx;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> str[i];
  }
  build(1, 0, n - 1);
  cin >> q;
  while (q--) {
    int tt;
    cin >> tt;
    if (tt) {
      int l, r;
      cin >> l >> r;
      cout << query(1, 0, n - 1, l, r) << '\n';
    } else {
      int l, r, val;
      cin >> l >> r >> val;
      val %= 5;
      update(1, 0, n - 1, l, r, val);
    }
  }
  return 0;
}