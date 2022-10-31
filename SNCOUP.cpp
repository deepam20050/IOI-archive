#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int cnt[2];

char s[2][N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    scanf("%s", s[0]);
    scanf("%s", s[1]);
    for (int i = 0; i < n; ++i) {
      if (s[0][i] == '*') {
        ++cnt[0];
      } 
      if (s[1][i] == '*') {
        ++cnt[1];
      }
    }
    bool hor = 0;
    int ans = 0;
    if (cnt[0] > 0 && cnt[1] > 0) {
      hor = 1;
    } else {
      ans = max(cnt[0], cnt[1]) - 1;
    } 
    printf("%d\n", ans);
  }
  return 0;
}

