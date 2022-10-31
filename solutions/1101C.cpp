// https://codeforces.com/contest/1101/problem/C

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector < pair < pair < int, int >, int > > arr;
int who[N];

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    arr.clear();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      int l, r;
      scanf("%d %d", &l, &r);
      arr.push_back({{l, r}, i});
    }
    sort(arr.begin(), arr.end());
    bool ok = 0;
    int r = arr[0].first.second;
    for (int i = 1; i < n; ++i) {
      if (arr[i].first.first > r) {
        ok = 1;
        for (int j = 0; j < n; ++j) {
          if (j < i) {
            who[arr[j].second] = 1;
          } else {
            who[arr[j].second] = 2;
          }
        }
        break;
      } else {
        r = max(r, arr[i].first.second);
      }
    }
    if (ok) {
      for (int i = 0; i < n; ++i) {
        printf("%d ", who[i]);
      }
    } else {
      printf("-1");
    }
    puts("");
  }
  return 0;
}