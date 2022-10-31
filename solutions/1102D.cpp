// https://codeforces.com/problemset/problem/1102/D

#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

char str[N];

int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", str);
  int x = n / 3;
  int a = 0, b = 0, c = 0;
  for (int i = 0; i < n; ++i) {
    a += str[i] == '0';
    b += str[i] == '1';
    c += str[i] == '2';
  }
  for (int i = 0; i < n; ++i) {
    if (str[i] == '1' && b > x) {
      if (a < x) {
        str[i] = '0';
        ++a;
        --b;
      }
    }
    if (str[i] == '2' && c > x) {
      if (a < x) {
        str[i] = '0';
        ++a;
        --c;
      } else if (b < x) {
        str[i] = '1';
        ++b;
        --c;
      }
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    if (str[i] == '0' && a > x) {
      if (c < x) {
        str[i] = '2';
        --a;
        ++c;
      } else if (b < x) {
        str[i] = '1';
        --a;
        ++b;
      }
    } else if (str[i] == '1' && b > x) {
      if (c < x) {
        str[i] = '2';
        --b;
        ++c;
      } else if (a < x) {
        str[i] = '0';
        --b;
        ++a;
      }
    } else if (str[i] == '2' && c > x) {
      if (b < x) {
        str[i] = '1';
        --c;
        ++b;
      } else if (a < x) {
        str[i] = '0';
        --c;
        ++a;
      }
    }
  }
  puts(str);
  return 0;
}