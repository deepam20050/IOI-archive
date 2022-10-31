#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

string str[N];

int f (const string &s) {
  int cnt = 0;
  for (int i = 0, scnt = 0; i < s.size(); ++i) {
    scnt += s[i] == 's';
    if (s[i] == 'h') {
      cnt += scnt;
    }
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> str[i];
  }
  sort(str, str + n, [&] (string &a, string &b) {
    return f(a + b) > f(b + a);
  });
  string s;
  for (int i = 0; i < n; ++i) {
    s += str[i];
  }
  cout << f(s);
  return 0;
}