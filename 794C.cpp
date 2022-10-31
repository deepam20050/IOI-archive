// http://codeforces.com/contest/794/problem/C
// AC

#include <bits/stdc++.h>

using namespace std;

int main() {
  string oleg, mor;
  cin >> oleg >> mor;
  int n = oleg.size();
  sort(oleg.begin(), oleg.end());
  sort(mor.begin(), mor.end(), greater <char> ());
  deque <char> a, b;
  for (int i = 0; i < (n + 1)/2; ++i) {
    a.push_back(oleg[i]);
  }
  for (int i = 0; i < n/2; ++i) {
    b.push_back(mor[i]);
  }
  string ans, ansr;
  bool mode = 0;
  for (int i = 0; i < n; ++i) {
    if (i & 1) {
      if (!a.empty() && a[0] >= b[0]) {
        mode = 1;
      }
      if (mode) {
        ansr += b.back();
        b.pop_back();
      } else {
        ans += b.front();
        b.pop_front();
      }
    } else {
      if (!b.empty() && a[0] >= b[0]) {
        mode = 1;
      }
      if (mode) {
        ansr += a.back();
        a.pop_back();
      } else {
        ans += a.front();
        a.pop_front();
      }
    }
  }
  reverse(ansr.begin(), ansr.end());
  cout << ans + ansr << '\n';
  return 0;
}

