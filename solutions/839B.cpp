// http://codeforces.com/contest/839/problem/B

#include <bits/stdc++.h>

using namespace std;

int have[5], cnt[5];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  have[2] = 2 * n;
  have[4] = n;
  for (int i = 0; i < k; ++i) {
    int x;
    scanf("%d", &x);
    while (x >= 3) {
      if (have[4] > 0) {
        --have[4];
        x -= 4;
      } else if (have[2] > 0) {
        --have[2];
        x -= 2;
      } else {
        return !printf("NO");
      }
    }
    ++cnt[x];
  }
  while (cnt[2]) {
    if (have[2] > 0) {
      --have[2];
      --cnt[2];
    } else if (have[4] > 0) {
      --have[4];
      --cnt[2];
      ++have[1];
    } else {
      --cnt[2];
      cnt[1] += 2;
    }
  }
  cnt[1] > have[1] + have[2] + have[4] * 2 ? puts("NO") : puts("YES");
  return 0;
}

