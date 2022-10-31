// http://codeforces.com/problemset/problem/160/C

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

map <int, long long> mp;

int main() {
  long long n, k;
  scanf("%lld %lld", &n, &k);
  for (int i = 0, x; i < n; ++i) {
    scanf("%d", &x);
    ++mp[x];
  }
  long long cnt = 1;
  int val = -1;
  for (auto &e: mp) {
    if (cnt <= k && k < cnt +  n * e.second) {
      val = e.first;
      break;
    }
    cnt = n * e.second + cnt;
  }
  long long peche = cnt;
  for (auto &e: mp) {
    if (peche <= k && k < peche + mp[val] * e.second) {
      return !printf("%d %d", val, e.first);
    }
    peche = peche + mp[val] * e.second;
  }
  return 0; 
}
