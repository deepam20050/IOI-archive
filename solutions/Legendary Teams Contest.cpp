// http://acm.timus.ru/problem.aspx?space=1&num=1208

#include <bits/stdc++.h>

using namespace std;

const int N = 123;

int a[N][3];
bool used[N];
unordered_map <string, int> mp;

int ans;
int n;
int cnt = 1;

void go(int i) {
  if (i == n) {
    ans = max(ans, accumulate(used, used + cnt, 0) / 3);
    return;
  }
  bool ok = 1;
  for (int j = 0; j < 3; ++j) {
    if (used[a[i][j]]) {
      ok = 0;
      break;
    }
  }
  if (ok) {
    for (int j = 0; j < 3; ++j) {
      used[a[i][j]] = 1;
    }
  }
  go(i + 1);
  if (ok) {
    for (int j = 0; j < 3; ++j) {
      used[a[i][j]] = 0;
    }
  }
  go(i + 1);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      string s;
      cin >> s;
      if (!mp[s]) {
        mp[s] = cnt++;
      }
      a[i][j] = mp[s];
    }
  }
  go(0);
  printf("%d", ans);
  return 0;
}