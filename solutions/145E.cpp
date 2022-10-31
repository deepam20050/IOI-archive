// http://codeforces.com/contest/145/problem/E

#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

struct node {
  bool lzy;
  int cnt4;
  int cnt7;
  int cnt47;
  int cnt74;
  node () {
    lzy = 0;
    cnt4 = 0;
    cnt7 = 0;
    cnt47 = 0;
    cnt74 = 0;
  }
};

node t[4 * N];
char s[N];
char tt[10];

int n;
int q;

node join (const node &a, const node &b) {
  node res;
  res.cnt4 = a.cnt4 + b.cnt4;
  res.cnt7 = a.cnt7 + b.cnt7;
  res.cnt47 = max(a.cnt47, b.cnt47);
  res.cnt74 = max(a.cnt74, b.cnt74);
  if (a.cnt4) {
    if (b.cnt47) {
      res.cnt47 = max(res.cnt47, a.cnt4 + b.cnt47);
    } 
    if (b.cnt7) {
      res.cnt47 = max(res.cnt47, a.cnt4 + b.cnt7);
    }
  }
  if (a.cnt47 && b.cnt7) {
    res.cnt47 = max(res.cnt47, a.cnt47 + b.cnt7);
  }
  if (a.cnt7) {
    if (b.cnt74) {
      res.cnt74 = max(res.cnt74, a.cnt7 + b.cnt74);
    }
    if (b.cnt4) {
      res.cnt74 = max(res.cnt74, a.cnt7 + b.cnt4);
    }
  }
  if (a.cnt74 && b.cnt4) {
    res.cnt74 = max(res.cnt74, a.cnt74 + b.cnt4);
  }
  return res;
}

void push (int i, int l, int r) {
  if (l < r && t[i].lzy) {
    t[i << 1].lzy ^= 1;
    t[i << 1 | 1].lzy ^= 1;
  } 
  if (t[i].lzy) {
    swap(t[i].cnt4, t[i].cnt7);
    swap(t[i].cnt47, t[i].cnt74);
    t[i].lzy = 0;
  }
}

void build (int i, int l, int r) {
  if (l == r) {
    s[l] == '7' ? t[i].cnt7 = 1 : t[i].cnt4 = 1;
    return;
  }
  int m = (l + r) >> 1;
  build(i << 1, l, m);
  build(i << 1 | 1, m + 1, r);
  t[i] = join(t[i << 1], t[i << 1 | 1]);
}

void update (int i, int l, int r, int x, int y) {
  push(i, l, r);
  if (x <= l && r <= y) {
    t[i].lzy ^= 1;
    return;
  }
  int m = (l + r) >> 1;
  if (x <= m) {
    update(i << 1, l, m, x, y);
  } 
  if (y > m) {
    update(i << 1 | 1, m + 1, r, x, y);
  }
  push(i << 1, l, m);
  push(i << 1 | 1, m + 1, r);
  t[i] = join(t[i << 1], t[i << 1 | 1]);
}

// node query (int i, int l, int r, int x, int y) {
//   push(i, l, r);
//   if (x <= l && r <= y) {
//     return t[i];
//   }
//   int m = (l + r) >> 1;
//   node res;
//   if (x <= m) {
//     res = join(res, query(i << 1, l, m, x, y));
//   }
//   if (y > m) {
//     res = join(res, query(i << 1 | 1, m + 1, r, x, y));
//   }
//   return res;
// }


int main() {
  scanf("%d %d", &n, &q);
  scanf("%s", s);
  build(1, 0, n - 1);
  while (q--) {
    scanf("%s", tt);
    if (tt[0] == 'c') {
      push(1, 0, n - 1);
      printf("%d\n", max(t[1].cnt4, max(t[1].cnt7, t[1].cnt47)));
    } else {
      int l, r;
      scanf("%d %d", &l, &r);
      --l;
      --r;
      update(1, 0, n - 1, l, r);
    }
    // for (int i = 0; i < n; ++i) {
    //   node res = query(1, 0, n - 1, i, i);
    //   int val = res.cnt4 ? 4 : 7;
    //   cout << val << " ";
    // }
    // cout << '\n';
  }
  return 0;
}