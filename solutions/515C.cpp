// http://codeforces.com/problemset/problem/515/C

#include <bits/stdc++.h>

using namespace std;

string f[10];
string str;

int main() {
  f[2] = "2";
  f[3] = "3";
  f[4] = "322";
  f[5] = "5";
  f[6] = "53";
  f[7] = "7";
  f[8] = "7222";
  f[9] = "7332";
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (char ch : s) {
    str += f[ch - '0'];
  }
  sort(str.rbegin(), str.rend());
  cout << str;
  return 0;
}