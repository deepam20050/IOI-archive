// http://codeforces.com/contest/709/problem/C

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

char s[N];

char prev(char ch) {
  if (ch == 'a') {
    return 'z';
  }
  return --ch;
}

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int l = 0;
  while (l < n) {
    char ch = prev(s[l]);
    if (ch < s[l]) {
      break;
    }
    ++l;
  }
  int r = l;
  while (r < n) {
    char ch = prev(s[r]);
    if (ch > s[r]) {
      break;
    }
    ++r;
  }
  if (l == n) {
    s[n - 1] = prev(s[n - 1]);
  }
  while (l < n && l < r) {
    s[l] = prev(s[l]);
    ++l;
  }
  puts(s);
  return 0;
}