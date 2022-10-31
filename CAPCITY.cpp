#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

vector <int> g[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    g[x].push_back(y);
  }
  return 0;
}