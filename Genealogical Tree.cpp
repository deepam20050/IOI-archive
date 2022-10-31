// http://acm.timus.ru/problem.aspx?space=1&num=1022

#include <bits/stdc++.h>

using namespace std;

const int N = 123;

vector <int> g[N];
bool used[N];
vector <int> v;

void dfs(int x) {
  used[x] = 1;
  for (int to : g[x]) {
    if (!used[to]) {
      dfs(to);
    }
  }
  v.emplace_back(x);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int x;
    while (scanf("%d", &x) && x) {
      g[i].emplace_back(x);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!used[i]) {
      dfs(i);
    }
  }
  reverse(v.begin(), v.end());
  for (int x : v) {
    printf("%d ", x);
  }
  return 0;
}