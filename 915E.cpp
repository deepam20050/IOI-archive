#include <bits/stdc++.h>

using namespace std;

struct data {
  data *lft;
  data *rgt;
  bool l_touch;
  bool r_touch;
  int len;
  data () {
    lft = nullptr;
    rgt = nullptr;
    l_touch = 0;
    r_touch = 0;
    len = 0;
  }
  void push (data *ptr, int l, int r, int k) {
    if (ptr == nullptr) {
      return;
    }
    if (ptr->lft == nullptr) {
      ptr->lft = new data();
    }
    if (ptr->rgt == nullptr) {
      ptr->rgt = new data();
    }
    int m = l + r >> 1;
    ptr->lft->l_touch = k == 2;
    ptr->lft->r_touch = k == 2;
    ptr->lft->len = k == 2 ? m - l + 1 : 0;
    ptr->rgt->l_touch = k == 2;
    ptr->rgt->r_touch = k == 2;
    ptr->rgt->len = k == 2 ? l - m : 0;
  }
  data* update (int l, int r, int x, int y, int k) {
    if (x <= l && r <= y) {
      l_touch = k == 2;
      r_touch = k == 2;
      len = k == 2 ? r - l + 1: 0;
      push(this, l, r, k);
      // cout << l << " " << r << " " << l_touch << " " << r_touch << " " << len << '\n';
      return this;
    }
    int m = l + r >> 1;
    if (x <= m) {
      if (lft == nullptr) {
        lft = new data();
      }
      lft = lft->update(l, m, x, y, k);
    }
    if (y > m) {
      if (rgt == nullptr) {
        rgt = new data();
      }
      rgt = rgt->update(m + 1, r, x, y, k);
    }
    l_touch = 1;
    r_touch = 1;
    len = 0;
    if (lft != nullptr && rgt == nullptr) {
      l_touch = lft->l_touch;
      r_touch = lft->r_touch;
      if (lft->r_touch) {
        len = lft->len + r - m;
      } else {
        len = r - m;
      }
      return this;
    }
    if (lft == nullptr && rgt != nullptr) {
      l_touch = rgt->l_touch;
      r_touch = rgt->r_touch;
      if (rgt->l_touch) {
        len = rgt->len + m - l + 1;
      } else {
        len = rgt->len;
      }
      return this;
    }
    l_touch = lft->l_touch;
    r_touch = rgt->r_touch;
    if (lft->r_touch && rgt->l_touch) {
      len = lft->len + rgt->len;
    } else if (rgt->len) {
      len = rgt->len;
    } else {
      len = lft->len;
      // cout << lft->len << '\n';
    }
    // cout << "LOG:: " << l << " " << r << " " << l_touch << " " << r_touch << " " << len << " " << ok << '\n';
    return this;
  }
};

data *root = new data();

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  root->l_touch = 1;
  root->r_touch = 1;
  root->len = n;
  while (q--) {
    int l, r, k;
    scanf("%d %d %d", &l, &r, &k);
    root = root->update(1, n, l, r, k);
    printf("%d\n", root->len);
  }
  return 0;
}