// https://www.codechef.com/AUG18B/problems/LONCYC
// Thanks G. Polya :)

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int M = 5e6 + 5;

vector < int > G[N];
bool used[N];
int color[N];
long long dp[N][2];
long long up[N][2];
long long one[N];
bool bridge[M];
long long print[M];
int from[M];
int too[M];
int tin[N];
queue < int > Q[N];
int n;
int m;
int timer;
int curr_no;

inline void init () {
  timer = 1;
  curr_no = 1;
  for (int i = 1; i <= n; ++i) {
    G[i].clear();
    used[i] = 0;
    dp[i][0] = 0;
    dp[i][1] = 0;
    up[i][0] = 0;
    up[i][1] = 0;
    one[i] = 0;
    color[i] = 0;
  }
  memset(bridge, 0, sizeof bridge);
}

inline int adj (int x, int e) {
  return from[e] == x ? too[e] : from[e];
}

int find_bridges (int u, int edge) {
  used[u] = 1;
  tin[u] = timer++;
  int dbe = tin[u];
  for (int nxt : G[u]) {
    int to = adj(u, nxt);
    if (!used[to]) {
      dbe = min(dbe, find_bridges(to, nxt));
    } else if (nxt != edge) {
      dbe = min(dbe, tin[to]);
    }
  }
  if (dbe == tin[u] && edge != -1) {
    bridge[edge] = 1;
  } 
  return dbe;
}

void build_tree (int x) {
  int curr_cmp = curr_no;
  Q[curr_cmp].push(x);
  color[x] = curr_cmp;
  while (!Q[curr_cmp].empty()) {
    int u = Q[curr_cmp].front();
    Q[curr_cmp].pop();
    for (int edge : G[u]) {
      int to = adj(u, edge);
      if (color[to]) continue;
      if (bridge[edge]) {
        ++curr_no;
        build_tree(to);
      } else {
        color[to] = curr_cmp;
        Q[curr_cmp].push(to);
      }
    }
  }
}

void dfs1 (int x, int pr) {
  used[x] = 1;
  for (int edge : G[x]) {
    int to = adj(x, edge);
    if (to == pr || color[x] == color[to]) continue;
    dfs1(to, x);
    dp[x][0] += 1 + dp[to][0];
  }
  for (int edge : G[x]) {
    int to = adj(x, edge);
    if (to == pr || color[x] == color[to]) continue;
    dp[x][0] -= 1 + dp[to][0];
    print[edge] = 1 + dp[x][0] + dp[to][0] + dp[x][0] * dp[to][0];
    dp[x][0] += 1 + dp[to][0];
  }
}

void dfs2 (int x, int pr, long long sum) {
  used[x] = 1;
  sum += dp[x][0];
  for (int edge : G[x]) {
    int to = adj(x, edge);
    if (to == pr || color[x] == color[to]) continue;
    sum -= dp[to][0];
    print[edge] += up[x][0]  + up[x][0] * dp[to][0];
    up[to][0] = sum;
    dfs2(to, x, sum);
    sum += dp[to][0];
  }
}

void dfs3 (int x, int pr) {
  used[x] = 1;
  dp[x][1] += one[x];
  for (int edge : G[x]) {
    int to = adj(x, edge);
    if (to == pr || color[x] == color[to]) continue;
    dfs3(to, x);
    dp[x][1] += dp[to][1];
  }
  for (int edge : G[x]) {
    int to = adj(x, edge);
    if (to == pr || color[x] == color[to]) continue;
    dp[x][1] -= dp[to][1];
    dp[x][0] -= 1 + dp[to][0];
    print[edge] += dp[to][1] + dp[x][1] + dp[to][1] * dp[x][0] + dp[to][0] * dp[x][1];
    dp[x][1] += dp[to][1];
    dp[x][0] += 1 + dp[to][0];
  }
}

void dfs4 (int x, int pr, long long sum) {
  sum += dp[x][1];
  for (int edge : G[x]) {
    int to = adj(x, edge);
    if (to == pr || color[x] == color[to]) continue;
    print[edge] += up[x][1] + up[x][1] * dp[to][0] + up[x][0] * dp[to][1];
    sum -= dp[to][1];
    up[to][1] = sum;
    dfs4(to, x, sum);
    sum += dp[to][1];
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    scanf("%d %d", &n, &m);
    init();
    for (int i = 0; i < m; ++i) {
      int x, y;
      scanf("%d %d", &x, &y);
      G[x].emplace_back(i);
      G[y].emplace_back(i);
      from[i] = x;
      too[i] = y;
    }
    for (int i = 1; i <= n; ++i) {
      if (!used[i]) {
        find_bridges(i, -1);
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (!color[i]) {
        build_tree(i);
      }
    }
    memset(used, 0, sizeof used);
    for (int i = 1; i <= n; ++i) {
      if (!used[i]) {
        dfs1(i, 0);
        dfs2(i, 0, 0);
      }
    }
    for (int i = 0; i < m; ++i) {
      if (!bridge[i]) {
        int x = from[i], y = too[i];
        print[i] = 1 + dp[x][0] * (dp[y][0] + up[y][0] + 1) + up[x][0] * (dp[y][0] + up[y][0] + 1) + dp[y][0] + up[y][0];
        one[x] += 1 + dp[y][0] + up[y][0];
        one[y] += 1 + dp[x][0] + up[x][0];
      }
    }
    memset(used, 0, sizeof used);
    for (int i = 1; i <= n; ++i) {
      if (!used[i]) {
        dfs3(i, 0);
        dfs4(i, 0, 0);
      }
    }
    for (int i = 0; i < m; ++i) {
      printf("%lld\n", print[i]);
    }
  }
  return 0;
}