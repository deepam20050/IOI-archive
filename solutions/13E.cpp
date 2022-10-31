// http://codeforces.com/contest/13/problem/E

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int SQN = 350;

int arr[N];
int cnt[N];
int nxt[N];

int n;
int q;
int blocks;

void update (int i, int x) {
  int l = i * SQN;
  int r = min(l + SQN, n);
  while (x >= l) {
    int aage = arr[x] + x;
    if (aage >= r) {
      nxt[x] = aage;
      cnt[x] = 0;
    } else {
      nxt[x] = nxt[aage];
      cnt[x] = cnt[aage] + 1; 
    }
    --x;
  }
}

int main() {
  fill(nxt, nxt + N, N);
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", arr + i);
  }
  blocks = n / SQN;
  for (int i = blocks; i >= 0; --i) {
    update(i, min((i + 1) * SQN - 1, n));
  }
  while (q--) {
    int tt;
    scanf("%d", &tt);
    if (tt) {
      int x;
      scanf("%d", &x);
      int res = 0;
      int lst = 0;
      while (1) {
        res += cnt[x] + 1;
        if (nxt[x] > n) {
          while (x <= n) {
            lst = x;
            x = arr[x] + x;
          }
          break;
        }
        x = nxt[x];
      }
      printf("%d %d\n", lst, res);
    } else {
      int x, y;
      scanf("%d %d", &x, &y);
      arr[x] = y;
      update(x / SQN, x);
    }
  }
  return 0;
}