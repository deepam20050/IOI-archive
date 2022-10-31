// https://www.acmicpc.net/problem/2270

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
const int mod = 1e6;

int tower[N];
int pw[N];
int sz[3];
int n;
int ans;

void solve (int disc, int dest) {
  if (disc < 0) {
    return;
  }
  if (tower[disc] == dest) {
    solve(disc - 1, dest);
  } else {
    solve(disc - 1, 3 - dest - tower[disc]);
    ans += pw[disc];
    if (ans >= mod) {
      ans -= mod;
    }
  }
}

int main() {
  pw[0] = 1;
  for (int i = 1; i < N; ++i) {
    pw[i] = pw[i - 1] << 1;
    pw[i] %= mod;
  }
  scanf("%d", &n);
  for (int i = 0; i < 3; ++i) {
    scanf("%d", sz + i);
  }
  for (int i = 0; i < 3; ++i) {
    for (int j = 0, x; j < sz[i]; ++j) {
      scanf("%d", &x);
      tower[x - 1] = i;
    }
  }
  printf("%d\n", 1 + tower[n - 1]);
  solve(n - 2, tower[n - 1]);
  printf("%d\n", ans);
  return 0;
}