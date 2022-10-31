// http://codeforces.com/contest/560/problem/D
// A good problem

#include <bits/stdc++.h>

using namespace std;

string solve (string s) {
  if (s.size() & 1) {
    return s;
  }
  string s1 = solve(s.substr(0, s.size() >> 1));
  string s2 = solve(s.substr((s.size() >> 1)));
  return s1 < s2 ? s1 + s2 : s2 + s1;
}

int main() {
  string a, b;
  cin >> a >> b;
  printf(solve(a) == solve(b) ? "YES" : "NO");
  return 0;
}