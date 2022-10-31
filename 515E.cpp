#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;

struct data {
  long long maxi;
  long long mini;
  int mini_pos;
  int maxi_pos;
  data () {
    maxi = -2e18;
    mini = 2e18;
    mini_pos = -1;
    maxi_pos = -1;
  }
};

data t[4 * N];
long long h[N + N];
long long dist[N];
long long prf[N + N];
int n, q;

data join (const data &a, const data &b) {
  data res;
  if (a.maxi > b.maxi) {
    res.maxi = a.maxi;
    res.maxi_pos = a.maxi_pos;
  } else {
    res.maxi = b.maxi;
    res.maxi_pos = b.maxi_pos;
  }
  if (a.mini < b.mini) {
    res.mini = a.mini;
    res.mini_pos = a.mini_pos;
  } else {
    res.mini = b.mini;
    res.mini_pos = b.mini_pos;
  }
  return res;
}

void build (int nk, int l, int r) {
  if (l == r) {
    t[nk].maxi = prf[l] + h[l];
    t[nk].maxi_pos = l;
    t[nk].mini = prf[l] - h[l];
    t[nk].mini_pos = l;
    return;
  }
  int m = l + r >> 1;
  build(nk << 1, l, m);
  build(nk << 1 | 1, m + 1, r);
  t[nk] = join(t[nk << 1], t[nk << 1 | 1]);
}

data query (int nk, int l, int r, int x, int y) {
  if (r < x || l > y || x > y) {
    return data();
  }
  if (x <= l && r <= y) {
    return t[nk];
  }
  int m = l + r >> 1;
  return join(query(nk << 1, l, m, x, y), query(nk << 1 | 1, m + 1, r, x, y));
}

int main() {
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", dist + i);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", h + i);
    h[i] <<= 1LL;
  }
  for (int i = n + 1; i <= n + n; ++i) {
    h[i] = h[i - n];
  }
  for (int i = 2; i <= n; ++i) {
    prf[i] = prf[i - 1] + dist[i - 1];
  }
  prf[n + 1] = prf[n] + dist[n];
  for (int i = 2; i <= n; ++i) {
    prf[n + i] = prf[i - 1] + dist[i - 1];
  }
  build(1, 1, n + n);
  while (q--) {
    int a, b;
    scanf("%d %d", &a, &b);
    int x, y;
    if (a <= b) {
      x = b + 1;
      y = a + n - 1;
    } else {
      x = a - b + 1;
      y = a - 1;
    }
    data node1 = query(1, 1, n + n, x, y);
    int maxi_pos = node1.maxi_pos;
    data node2 = query(1, 1, n + n, x, maxi_pos - 1);
    data node3 = query(1, 1, n + n, maxi_pos + 1, y);
    int mini_pos1 = node2.mini_pos;
    int mini_pos2 = node3.mini_pos;
    long long mini;
    if (mini_pos1 != -1 && mini_pos2 != -1) {
      mini = min(node2.mini, node3.mini);
    } else if (mini_pos1 == -1) {
      mini = node3.mini_pos;
    } else if (mini_pos2 == -1) {
      mini = node2.mini_pos;
    }
    cout << node1.maxi << " " << mini << '\n';
    printf("%lld\n", node1.maxi - mini);
  }
  return 0;
}