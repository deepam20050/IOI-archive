#include <bits/stdc++.h>

using namespace std;

const int N = 3e3 + 5;

int votes1[N];
int votes2[N];
pair < int, int > pi[N];
int n;
int m;

inline bool check1 () {
  for (int i = 2; i <= m; ++i) {
    if (votes1[i] >= votes1[1]) {
      return 0;
    }
  }
  return 1;
}

inline bool check2 () {
  for (int i = 2; i <= m; ++i) {
    if (votes2[i] >= votes2[1]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int p, c;
    cin >> p >> c;
    ++votes1[p];
    ++votes2[p];
    pi[i] = {c, p};
  }
  sort(pi, pi + n);
  if (check1()) {
    cout << "0";
    return 0;
  }
  int sum1 = 0;
  for (int i = 0; i < n; ++i) {
    int c = pi[i].first;
    int p = pi[i].second;
    --votes1[p];
    ++votes1[1];
    sum1 += c;
    if (check1()) {
      break;
    }
  }
  int sum2 = 0;
  for (int i = 0; i < n; ++i) {
    int mx = 0;
    for (int j = 2; j <= m; ++j) {
      mx = max(mx, votes2[j]);
    }
    int idx = 0;
    for (int j = i; j < n; ++j) {
      if (pi[i].second != 1 && votes2[pi[i].second] == mx) {
        idx = j;
        break;
      }
    }
    --votes2[pi[idx].second];
    ++votes2[1];
    if (check2() && sum2 + pi[idx].first <= sum1) {
      cout << sum2 + pi[idx].first;
      return 0;
    }
    ++votes2[pi[idx].second];
     int c = pi[i].first;
     int p = pi[i].second;
     --votes2[p];
     sum2 += c;
  }
  cout << min(sum1, sum2);
  return 0;
}