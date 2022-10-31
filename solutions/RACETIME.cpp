// http://www.spoj.com/problems/RACETIME/

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int SQN = 350;

int arr[N];
int sz[SQN];
int sorted[SQN][SQN];
char s[10];

int n;
int q;
int blocks;

void update (int i) {
  int l = i * SQN;
  int r = min(l + SQN - 1, n - 1);
  sz[i] = r - l + 1;
  int idx = 0;
  while (l <= r) {
    sorted[i][idx++] = arr[l++];
  }
  sort(sorted[i], sorted[i] + sz[i]);
}

int query (int x, int y, int val) {
  int ans = 0;
  int l = x / SQN;
  int r = y / SQN;
  if (l == r) {
    while (x <= y) {
      ans += arr[x++] <= val;
    }
  } else {
    for (int i = x, end = (l + 1) * SQN - 1; i <= end; ++i) {
      ans += arr[i] <= val;
    }
    for (int i = l + 1; i < r; ++i) {
      int idx = lower_bound(sorted[i], sorted[i] + sz[i], val) - sorted[i];
      while (idx >= 0 && (idx == sz[i] || sorted[i][idx] > val)) {
        --idx;
      }
      ans += idx + 1;
    }
    for (int i = r * SQN; i <= y; ++i) {
      ans += arr[i] <= val;
    }
  }
  return ans;
}

int main() {
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
  }
  blocks = n / SQN;
  for (int i = 0; i <= blocks; ++i) {
    update(i);
  }
  while (q--) {
    scanf("%s", s);
    if (s[0] == 'M') {
      int x, y;
      scanf("%d %d", &x, &y);
      --x;
      arr[x] = y;
      update(x / SQN);
    } else {
      int x, y, val;
      scanf("%d %d %d", &x, &y, &val);
      --x;
      --y;
      printf("%d\n", query(x, y, val));
    }
  }
  return 0;
}