// http://codeforces.com/problemset/problem/796/C

#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

vector <int> g[N];
multiset <int> st;
int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    st.insert(a[i]);
  }
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int ans = 1e9 + 10;
  for (int i = 1; i <= n; ++i) {
    st.erase(st.find(a[i]));
    int temp = a[i];
    for (int to: g[i]) {
      st.erase(st.find(a[to]));
      temp = max(temp, a[to] + 1);
    }
    if (!st.empty()) {
      temp = max(temp, *prev(st.end()) + 2);
    }
    st.insert(a[i]);
    for (int to: g[i]) {
      st.insert(a[to]);
    }
    ans = min(ans, temp);
  }
  printf("%d", ans);
  return 0;
}

