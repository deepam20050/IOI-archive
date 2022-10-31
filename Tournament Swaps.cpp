// https://csacademy.com/contest/archive/task/tournament-swaps

#include <bits/stdc++.h>

using namespace std;
using pi = pair <int, int>;

const int N = 1 << 17;

int a[N];
int best[22];

pi find_sol(const pi &a, const pi &b) {
  int t[] = {a.first, a.second, b.first, b.second};
  sort(t, t + 4, greater <int> ());
  return pi(t[0], t[1]);
}

pi solve (int l, int r, int depth) {
  if (l + 1 == r) {
    best[depth] = min(best[depth], min(a[l], a[r]));
    return pi(max(a[l], a[r]), min(a[l], a[r]));
  }
  int m = (l + r) >> 1;
  pi L = solve(l, m, depth + 1);
  pi R = solve(m + 1, r, depth + 1);
  pi sol = find_sol(L, R);
  best[depth] = min(best[depth], sol.second);
  return sol;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int w;
    scanf("%d", &w);
    int n = 1 << w;
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
      --a[i];
    }
    fill(best + 1, best + w + 1, n);
    solve(0, n - 1, 1);
    for (int i = 0; i < n; ++i) {
      int ans = 0;
      for (int j = 1; j <= w; ++j) {
        if (best[j] < i) {
          ans = w - j + 1;
          break;
        }
      }
      printf("%d ", ans);
    }
    puts("");
  }
  return 0;
}