// https://www.codechef.com/problems/COOK82A
// AC
#include <bits/stdc++.h>

using namespace std;

map <string, int> mp;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < 4; ++i) {
      string s;
      int foo;
      cin >> s >> foo;
      mp[s] = foo;
    }
    if (mp["Barcelona"] > mp["Eibar"] && mp["RealMadrid"] < mp["Malaga"]) {
      puts("Barcelona");
    } else {
      puts("RealMadrid");
    }
  }
  return 0;
}

