// https://www.codechef.com/problems/PRCS16E

#include <bits/stdc++.h>

using namespace std;

const int N = 50010;
const long long mod = 1e9 + 7;

struct node {
  long long ans;
  long long abb[10][10];
  long long bba[10][10];
  long long ab[10][10];
  long long a[10];
  node () {
    ans = 0;
    memset(abb, 0, sizeof abb);
    memset(bba, 0, sizeof bba);
    memset(ab, 0, sizeof ab);
    memset(a, 0, sizeof a);
  }
};

node t[4 * N];
char s[N];

int n;
int q;

node join (const node &a, const node &b) {
  node res;
  res.ans = (a.ans + b.ans) % mod;
  for (int i = 0; i < 10; ++i) {
    res.a[i] = a.a[i] + b.a[i];
    for (int j = 0; j < 10; ++j) {
      res.ans += (a.ab[i][j] * b.ab[j][i]) % mod + (a.abb[i][j] * b.a[i]) % mod + (a.a[i] * b.bba[j][i]) % mod;
      res.ans %= mod;
      res.ab[i][j] = a.ab[i][j] + b.ab[i][j] + (a.a[i] * b.a[j]) % mod;
      res.ab[i][j] %= mod;
      res.abb[i][j] = a.abb[i][j] + b.abb[i][j] + (a.ab[i][j] * b.a[j]) % mod + (a.a[i] * b.ab[j][j]) % mod;
      res.abb[i][j] %= mod;
      res.bba[i][j] = a.bba[i][j] + b.bba[i][j] + (a.ab[i][i] * b.a[j]) % mod + (a.a[i] * b.ab[i][j]) % mod;
      res.bba[i][j] %= mod;
    }
  }
  return res;
}

void build (int i, int l, int r) {
  if (l == r) {
    t[i].a[s[l] - '0'] = 1;
    return;
  }
  int m = (l + r) >> 1;
  build(i << 1, l, m);
  build(i << 1 | 1, m + 1, r);
  t[i] = join(t[i << 1], t[i << 1 | 1]);
}

void update (int i, int l, int r, int x, int y) {
  if (l == r) {
    memset(t[i].a, 0, sizeof t[i].a);
    t[i].a[y] = 1;
    return;
  }
  int m = (l + r) >> 1;
  if (x <= m) {
    update(i << 1, l, m, x, y);
  } else {
    update(i << 1 | 1, m + 1, r, x, y);
  }
  t[i] = join(t[i << 1], t[i << 1 | 1]);
}

node query (int i, int l, int r, int x, int y) {
  if (x <= l && r <= y) {
    return t[i];
  }
  int m = (l + r) >> 1;
  node ret;
  if (x <= m) {
    ret = join(ret, query(i << 1, l, m, x, y));
  }
  if (y > m) {
    ret = join(ret, query(i << 1 | 1, m + 1, r, x, y));
  }
  return ret;
}

int main() {
  scanf("%s", s);
  n = strlen(s);
  build(1, 0, n - 1);
  scanf("%d", &q);
  while (q--) {
    int tt, x, y;
    scanf("%d %d %d", &tt, &x, &y);
    if (tt == 1) {
      printf("%lld\n", query(1, 0, n - 1, x - 1, y - 1).ans);
    } else {
      update(1, 0, n - 1, x - 1, y);
    }
  }
  return 0;
}