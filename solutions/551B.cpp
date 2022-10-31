// http://codeforces.com/contest/551/problem/B
// AC

#include <bits/stdc++.h>

using namespace std;

string s[3];

int cnt[3][26];

int main() {
  for (int i = 0; i < 3; ++i) {
    cin >> s[i];
    for (const auto &e: s[i]) {
      ++cnt[i][e - 'a'];
    }
  }
  int mn = 1e9;
  for (int i = 0; i < 26; ++i) {
    if (cnt[1][i]) {
      mn = min(mn, cnt[0][i] / cnt[1][i]);
    }
  }
  int ans1 = 0, ans2 = 0;
  for (int i = 0; i <= mn; ++i) {
    int temp = 1e9;
    for (int j = 0; j < 26; ++j) {
      if (cnt[2][j]) {
        temp = min(temp, (cnt[0][j] - cnt[1][j] * i) / cnt[2][j]);
      }
    }
    if (ans1 + ans2 < temp + i) {
      ans1 = i;
      ans2 = temp;
    }
  }
  for (int i = 0; i < 26; ++i) {
    while (cnt[0][i] - ans1 * cnt[1][i] - ans2 * cnt[2][i]) {
      cout << char(i + 'a');
      --cnt[0][i];
    }
  }
  while (ans1--) {
    cout << s[1];
  }
  while (ans2--) {
    cout << s[2];
  }
  return 0;
}

