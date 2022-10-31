// https://www.codechef.com/problems/HILLJUMP

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int SQN = 350;

long long arr[N];
int nxt[N];
int cnt[N];
long long lzy[SQN];

int n;
int q;
int blocks;

void update (int x) {
  if (x < 0) {
    return;
  }
  for (int i = x * SQN; i < min((x + 1) * SQN, n); ++i) {
    arr[i] += lzy[x];
  }
  for (int i = (x + 1) * SQN; i < min((x + 2) * SQN, n); ++i) {
    arr[i] += lzy[x + 1];
  }
  lzy[x] = 0;
  lzy[x + 1] = 0;
  stack <int> s;
  int l = x * SQN;
  int r = min(l + SQN - 1, n - 1);
  for (int i = min(r + 100, n - 1); i > r; --i) {
    s.push(i);
  }
  for (int i = r; i >= l; --i) {
    while (!s.empty() && arr[s.top()] <= arr[i]) {
      s.pop();
    }
    if (s.empty() || s.top() - i > 100) {
      nxt[i] = -1;
      cnt[i] = 0;
    } else {
      int aage = s.top();
      if (aage > r) {
        nxt[i] = aage;
        cnt[i] = 0;
      } else {
        nxt[i] = nxt[aage];
        cnt[i] = cnt[aage] + 1;
      }
    }
    s.push(i);
  }
}

void range_update (int l, int r, int x) {
  int b_l = l / SQN;
  int b_r = r / SQN;
  if (b_l == b_r) {
    while (l <= r) {
      arr[l++] += x;
    }
    update(b_l);
    update(b_l - 1);
    return;
  }
  for (int i = l, end = (b_l + 1) * SQN; i < end; ++i) {
    arr[i] += x;
  }
  for (int i = b_l + 1; i < b_r; ++i) {
    lzy[i] += x;
  }
  for (int i = b_r * SQN; i <= r; ++i) {
    arr[i] += x;
  }
  update(b_r);
  update(b_l - 1);
  if (b_l < b_r - 1) {
    update(b_l);
  }
  update(b_r - 1);
}

int query (int idx, int k) {
  int jumps = 0;
  int lst = idx;
  while(1) {
    lst = idx;
    if (nxt[idx] == -1) {
      int blck = idx / SQN;
      int r = min((blck + 1) * SQN - 1, n - 1);
      while (idx <= r && jumps < k && idx - lst <= 100) {
        if (arr[idx] + lzy[blck] > arr[lst] + lzy[blck]) {
          lst = idx;
          ++jumps;
        }
        ++idx;
      }
      break;
    } 
    if (jumps + cnt[idx] + 1 > k) {
      int blck = idx / SQN;
      int r = min((blck + 1) * SQN - 1, n - 1);
      while (idx <= r && jumps < k && idx - lst <= 100) {
        if (arr[idx] + lzy[blck] > arr[lst] + lzy[blck]) {
          lst = idx;
          ++jumps;
        }
        ++idx;
      }
      break;
    }
    jumps += cnt[idx] + 1;
    idx = nxt[idx];
  }
  return lst + 1;
}

int main() {
  memset(nxt, -1, sizeof nxt);
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", arr + i);
  }
  blocks = n / SQN;
  for (int i = blocks; i >= 0; --i) {
    update(i);
  }
  while (q--) {
    int tt;
    scanf("%d", &tt);
    if (tt == 1) {
      int i, k;
      scanf("%d %d", &i, &k);
      printf("%d\n", query(i - 1, k));
    } else {
      int l, r, x;
      scanf("%d %d %d", &l, &r, &x);
      range_update(l - 1, r - 1, x);
    }
  }
  return 0;
}