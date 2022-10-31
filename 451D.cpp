// http://codeforces.com/problemset/problem/451/D
// AC

#include <bits/stdc++.h>

using namespace std;

int posodd[2], poseven[2];

int main() {
  string s;
  cin >> s;
  long long aodd = 0, aeven = 0;
  for (int i = 0; i < s.size(); ++i) {
    int id = s[i] - 'a';
    ++aodd;
    if (i & 1) {
      aodd += posodd[id];
      aeven += poseven[id];
      ++posodd[id];
    } else {
      aeven += posodd[id];
      aodd += poseven[id];
      ++poseven[id];
    }
  }
  printf("%lld %lld\n", aeven, aodd);
  return 0;
}

