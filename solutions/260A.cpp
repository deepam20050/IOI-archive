// http://codeforces.com/problemset/problem/260/A
// AC

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

int main() {
  ll a, b, n;
  cin >> a >> b >> n;
  ll num = a;
  for (int i = 1; i <= n; ++i) {
    num *= 10;
    bool flag = 1;
    for (int d = 0; d <= 9; ++d) {
      if ((num + d) % b == 0) {
        num += d;
        flag = 0;
        cout << num;
        ++i;
        while (i <= n) {
          putchar('0');
          ++i;
        }
        return 0;
      }
    }
    if (flag) {
      return !printf("-1");
    }    
  }
  return 0;
}

