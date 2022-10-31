// https://dmoj.ca/problem/ccc07s3

#include <bits/stdc++.h>

using namespace std;

const int N = 10010;

bool used[N];
int bro[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    bro[x] = y;
  }
  int u, v;
  while (scanf("%d %d", &u, &v) && u != 0) {
    memset(used, 0, sizeof used);
    int dist = -1;
    while (!used[u] && u != v) {
      used[u] = 1;
      ++dist;
      u = bro[u];
    }
    if (u == v) {
      printf("Yes %d\n", dist);
    } else {
      puts("No");
    }
  }
  return 0;
}