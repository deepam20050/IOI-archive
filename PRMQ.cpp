// https://www.codechef.com/problems/PRMQ

#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

const int N = 100001;
const int M = 1000001;

struct node {
  vector <int> v;
  vector <int> s;
};

node t[4 * N];
int a[N];
vector <int> primes;
bool p[M];

node join(const node &a, const node &b) {
  node res;
  res.v = {0};
  res.s = {0};
  int i = 1;
  int j = 1;
  int n = a.v.size();
  int m = b.v.size();
  int pref = 0;
  while (i < n && j < m) {
    if (a.v[i] < b.v[j]) {
      pref += a.s[i] - a.s[i - 1];
      res.v.emplace_back(a.v[i]);
      ++i;
    } else if (a.v[i] > b.v[j]) {
      pref += b.s[j] - b.s[j - 1];
      res.v.emplace_back(b.v[j]);
      ++j;
    } else {
      pref += a.s[i] - a.s[i - 1] + b.s[j] - b.s[j - 1];
      res.v.emplace_back(a.v[i]);
      ++i;
      ++j;
    }
    res.s.emplace_back(pref);
  }
  while (i < n) {
    pref += a.s[i] - a.s[i - 1];
    res.v.emplace_back(a.v[i]);
    res.s.emplace_back(pref);
    ++i;
  }
  while (j < m) {
    pref += b.s[j] - b.s[j - 1];
    res.v.emplace_back(b.v[j]);
    res.s.emplace_back(pref);
    ++j;
  }
  return res;
}

void build(int i, int l, int r) {
  if (l == r) {
    t[i].v = {0};
    t[i].s = {0};
    int n = a[l];
    int pref = 0;
    for (int x : primes) {
      if (x * x > n) {
        break;
      }
      if (n % x == 0) {
        while (n % x == 0) {
          ++pref;
          n /= x;
        }
        t[i].v.emplace_back(x);
        t[i].s.emplace_back(pref);
      }
    }
    if (n >= 2) {
      t[i].v.emplace_back(n);
      t[i].s.emplace_back(pref + 1);
    }
    return;
  }
  int m = (l + r) >> 1;
  build(i << 1, l, m);
  build(i << 1 | 1, m + 1, r);
  t[i] = join(t[i << 1], t[i << 1 | 1]);
}

int calc(int i, int a, int b) {
  int w = lower_bound(t[i].v.begin(), t[i].v.end(), b) - t[i].v.begin();
  int e = lower_bound(t[i].v.begin(), t[i].v.end(), a) - t[i].v.begin();
  while (w == t[i].v.size() || t[i].v[w] > b) {
    --w;
  }
  while (e == t[i].v.size() || t[i].v[e] >= a) {
    --e;
  }
  return t[i].s[w] - t[i].s[e];
}

int query(int i, int l, int r, int x, int y, int a, int b) {
  if (x <= l && r <= y) {
    return calc(i, a, b);
  }
  int m = (l + r) >> 1;
  int ret = 0;
  if (x <= m) {
    ret = query(i << 1, l, m, x, y, a, b);
  }
  if (y > m) {
    ret += query(i << 1 | 1, m + 1, r, x, y, a, b);
  }
  return ret;
}

int main() {
  for (int i = 2; i * i < M; ++i) {
    if (!p[i]) {
      primes.emplace_back(i);
      for (int j = i * i; j < M; j += i) {
        p[j] = 1;
      }
    }
  }
  int n;
  scan(n);
  for (int i = 0; i < n; ++i) {
    scan(a[i]);
  }
  build(1, 0, n - 1);
  int q;
  scan(q);
  while (q--) {
    int l, r, x, y;
    scan(l);
    scan(r);
    scan(x);
    scan(y);
    printf("%d\n", query(1, 0, n - 1, l - 1, r - 1, x, y));
  }
  return 0;
}