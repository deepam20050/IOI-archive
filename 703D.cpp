#include <bits/stdc++.h>

using namespace std;

struct query {
  int l;
  int r;
  int id;
  int blck;
  query () { }
  query (int _l, int _r, int _id) {
    l = _l;
    r = _r;
    id = _id;
    blck = _id / SQN;
  }
  bool operator < (const query &a) const {
    return blck < a.blck ? a.r < b.r : blck < a.blck;
  }
} Q[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", arr + i);
  }
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    Q[i] = query(l, r, i);
  }
  sort(Q, Q + q);
  int mo_lft = 0;
  int mo_right = 1;
  for (int i = 0; i < q; ++i) {
    int l = Q[i].l;
    int r = Q[i].r;
    while (mo_lft )
  }
  return 0;
}