// https://www.codechef.com/problems/CHEFEXQ

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int BLCK = 400;

int arr[N];
int xors[BLCK];
vector <int> sorted[BLCK];

int n;
int q;
int blocks;

void update (int i) {
  int l = i * BLCK;
  int r = l + BLCK - 1;
  r = min(r, n - 1);
  int prf = 0;
  sorted[i].clear();
  while (l <= r) {
    prf ^= arr[l++];
    sorted[i].emplace_back(prf);
  }
  xors[i] = prf;
  sort(sorted[i].begin(), sorted[i].end());
}

int query (int idx, int k) {
  int ans = 0;
  int prf = 0;
  int st_block = 0;
  int end_block = idx / BLCK;
  while (st_block < end_block) {
    int need = prf ^ k;
    ans += upper_bound(sorted[st_block].begin(), sorted[st_block].end(), need) - lower_bound(sorted[st_block].begin(), sorted[st_block].end(), need);
    prf ^= xors[st_block++];
  }
  for (int i = st_block * BLCK; i <= idx; ++i) {
    prf ^= arr[i];
    ans += prf == k;
  }
  return ans;
}

int main() {
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
  }
  blocks = n / BLCK;
  for (int i = 0; i < blocks; ++i) {
    update(i);
  }
  while (q--) {
    int tt, x, y;
    scanf("%d %d %d", &tt, &x, &y);
    --x;
    if (tt == 1) {
      arr[x] = y;
      update(x / BLCK);
    } else {
      printf("%d\n", query(x, y));
    }
  }
  return 0;
}