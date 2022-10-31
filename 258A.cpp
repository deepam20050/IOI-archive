// http://codeforces.com/problemset/problem/258/A
// AC

#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  int sum = 0;
  for (const auto &e: s) {
    sum += e - '0';
  }
  int n = s.size();
  if (sum == 0 || sum == n) {
    for (int i = 1; i < n; ++i) {
      cout << s[i];
    }
    return 0;
  }
  int i = 0; 
  while (i < n) {
    if (s[i] == '0') {
      break;
    }
    ++i;
  } 
  for (int j = 0; j < i; ++j) {
    cout << s[j];
  }
  ++i;
  while (i < n) {
    cout << s[i];
    ++i;
  }
  return 0;
}

