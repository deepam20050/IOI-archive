// http://codeforces.com/problemset/problem/959/D

#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 1;

vector <int> p[N];
bool used[N];
set <int> st;

int main() {
  for (int i = 2; i < N; ++i) {
    st.insert(i);
    if (p[i].empty()) {
      for (int j = i; j < N; j += i) {
        p[j].emplace_back(i);
      }
    }
  }
  int n;
  scanf("%d", &n);
  bool change = 0;
  for (int i = 0, x; i < n; ++i) {
    scanf("%d", &x);
    int ans = 0;
    if (change) {
      ans = *st.begin();
    } else {
      ans = *st.lower_bound(x);
      if (ans != x) {
        change = 1;
      }
    }
    printf("%d ", ans);
    for (int pr : p[ans]) {
      for (int j = pr; j < N; j += pr) {
        if (!used[j]) {
          st.erase(j);
          used[j] = 1;
        }
      }
    }
  }
  return 0;
}