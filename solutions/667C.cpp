// http://codeforces.com/contest/667/problem/C

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

bool yes[N][2];
set <string> v;
string s;

int main() {
  cin >> s;
  int n = s.size();
  yes[n - 2][0] = yes[n - 3][1] = 1;
  for (int i = n - 4; i >= 5; --i) {
    if (s[i + 2] == s[i] && s[i + 3] == s[i + 1]) {
      yes[i][0] = yes[i + 2][1];
    } else {
      yes[i][0] = yes[i + 2][0] | yes[i + 2][1];
    }
    if (s[i + 3] == s[i] && s[i + 4] == s[i + 1] && s[i + 5] == s[i + 2]) {
      yes[i][1] = yes[i + 3][0];
    } else {
      yes[i][1] = yes[i + 3][0] | yes[i + 3][1];
    }
  }
  for (int i = 5; i < n; ++i) {
    if (yes[i][0]) {
      v.insert(s.substr(i, 2));
    }
    if (yes[i][1]) {
      v.insert(s.substr(i, 3));
    }
  }
  cout << v.size() << '\n';
  for (const string &str : v) {
    cout << str << '\n';
  }
	return 0;
}

