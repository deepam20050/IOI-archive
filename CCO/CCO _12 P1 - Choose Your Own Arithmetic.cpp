#include <bits/stdc++.h>

using namespace std;

const int N = 7e5 + 1;

bool used[N][10];
int a[10];

int w;
int x;
int k;
bool ok;

void dfs(int z, int steps) {
  if (steps > w) {
    return;
  }
  if (z == x && steps == w) {
    ok = 1;
    return;
  }
  used[z][steps] = 1;
  for (int i = 0; i < k && !ok; ++i) {
    int val1 = z + a[i];
    int val2 = z * a[i];
    if (val1 <= x && !used[val1][steps]) {
      dfs(val1, steps + 1);
    }
    if (!ok && val2 <= x && !used[val2][steps]) {
      dfs(val2, steps + 1);
    }
  }
}

int main() {
  scanf("%d %d", &w, &k);
  for (int i = 0; i < k; ++i) {
    scanf("%d", a + i);
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &x);
    ok = 0;
    for (int i = 0; i < k && !ok; ++i) {
      memset(used, 0, sizeof used);
      dfs(a[i], 0);
    }
    ok ? puts("Y") : puts("N");
  }
  return 0;
}