// https://csacademy.com/contest/round-57/task/foxes-on-a-wheel/statement/

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

bool foxes[N], hide[N];

int n, k;

int b (int x) {
  return x == 1 ? n : x - 1;
}

int f (int x) {
  return x == n ? 1 : x + 1;
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < k; ++i) {
    int x;
    scanf("%d", &x);
    foxes[x] = 1;
  }
  for (int i = 0; i < k; ++i) {
    int x;
    scanf("%d", &x);
    hide[x] = 1;
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) { // considering only foxes
    if (!foxes[i]) {
      continue;
    }
    if (hide[f(i)] && !foxes[f(i + 1)]) {
      foxes[i] = 0;
      hide[f(i)] = 0;
      ++ans;
      continue;
    } 
    if (hide[b(i)] && !foxes[b(i - 1)]) {
      foxes[i] = 0;
      hide[b(i)] = 0;
      ++ans;
      continue;
    }
    if (hide[b(i)]) {
      foxes[i] = 0;
      hide[b(i)] = 0;
      ++ans;
      continue;
    }
    if (hide[f(i)]) {
      foxes[i] = 0;
      hide[f(i)] = 0;
      ++ans;
      continue;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (foxes[i]) {
      ans += 2;
    }
  }
  printf("%d\n", ans);
  return 0;
}