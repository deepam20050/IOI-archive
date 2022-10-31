// https://codeforces.com/problemset/problem/35/C

#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;

bool used[N][N];
queue < pair < int, pair < int, int > > > q;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int n;
int m;
int k;

inline bool check (int x, int y, int i) {
  return x + dx[i] <= n && x + dx[i] >= 1 && y + dy[i] <= m && y + dy[i] >= 1;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d %d", &n, &m);
  scanf("%d", &k);
  for (int i = 0; i < k; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    q.push({0, {a, b}});
    used[a][b] = 1;
  }
  int ans = 0;
  int ans_x = 0;
  int ans_y = 0;
  while (!q.empty()) {
    int x = q.front().second.first, y = q.front().second.second, d = q.front().first;
    if (d >= ans) {
      ans_x = x;
      ans_y = y;
      ans = d;
    }
    q.pop();
    for (int i = 0; i < 4; ++i) {
      if (check(x, y, i) && !used[x + dx[i]][y + dy[i]]) {
        used[x + dx[i]][y + dy[i]] = 1;
        q.push({1 + d, {x + dx[i], y + dy[i]}});
      }
    }
  } 
  printf("%d %d\n", ans_x, ans_y);
  return 0;
}