// https://dmoj.ca/problem/ccc13s4

#include <bits/stdc++.h>

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

const int N = 1000010;

bool used[N];
vector <int> g[N];

void bfs(int x) {
  memset(used, 0, sizeof used);
  queue <int> q;
  q.push(x);
  while (!q.empty()) {
    int u = q.front();
    used[u] = 1;
    q.pop();
    for (int to : g[u]) {
      if (!used[to]) {
        q.push(to);
      }
    }
  }
}

bool check(int u, int v) {
  bfs(u);
  return used[v];
}

int main() {
  int n, m;
  scan(n);
  scan(m);
  while (m--) {
    int x, y;
    scan(x);
    scan(y);
    g[x].emplace_back(y);
  }
  int p, q;
  scan(p);
  scan(q);
  if (check(p, q)) {
    puts("yes");
  } else if (check(q, p)) {
    puts("no");
  } else {
    puts("unknown");
  }
  return 0;
}