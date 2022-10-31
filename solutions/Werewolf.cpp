// http://acm.timus.ru/problem.aspx?space=1&num=1242

#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

vector <int> g[N];
vector <int> p[N];
bool used[N];
bool dead[N];

bool yes;

void dfs1(int x) {
  if (dead[x]) {
    yes = 1;
  }
  used[x] = 1;
  for (int to : p[x]) {
    if (!used[to]) {
      dfs1(to);
    }
  }
}

 void dfs2(int x) {
  if (dead[x]) {
    yes = 1;
  }
  used[x] = 1;
  for (int to : g[x]) {
    if (!used[to]) {
      dfs2(to);
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  string ttt;
  while (cin >> ttt && ttt[0] != 'B') {
    int x = stoi(ttt);
    int y;
    scanf("%d", &y);
    g[y].push_back(x);
    p[x].push_back(y);
  }
  int t;
  while (scanf("%d", &t) != EOF) {
    dead[t] = 1;
  }
  bool ok = 1;
  for (int i = 1; i <= n; ++i) {
    memset(used, 0, sizeof used);
    yes = 0;
    dfs1(i);
    if (yes) {
      continue;
    }
    memset(used, 0, sizeof used);
    yes = 0;
    dfs2(i);
    if (!yes) {
      printf("%d ", i);
      ok = 0;
    }
  }
  if (ok) {
    printf("0\n");
  }
  return 0;
}