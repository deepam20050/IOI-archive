#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

vector <int> g[N];
int d[N];
int c[N];
int p[N];
int sum[N];
bool haan[N];
pair <int, int> pi[N];
queue <int> q;

int main() {
  int n, b;
  scanf("%d %d", &n, &b);
  for (int i = 1; i <= n; ++i) {
    if (i == 1) {
      scanf("%d %d", d + i, c + i);
      pi[i] = {d[i], i};
    } else {
      int p;
      scanf("%d %d %d", d + i, c + i, &p);
      g[p].emplace_back(i);
      pi[i] = {d[i], i};
    }
  }
  sort(pi + 1, pi + n + 1);
  q.push(1);
  sum[1] = d[1] - c[1];
  int ans = 0;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int to : g[x]) {
      if (d[to] - c[to] + sum[x] > b) {
        continue;
      }
      q.push(to);
      p[to] = x;
      sum[to] = d[to] - c[to] + sum[x];
    }
    memset(haan, 0, sizeof haan);
    int curr = x;
    int tmp = sum[x];
    int elements = 0;
    while (curr) {
      haan[curr] = 1;
      curr = p[curr];
      ++elements;
    }
    for (int i = 1; i <= n; ++i) {
      if (!haan[pi[i].second] && pi[i].first + tmp <= b) {
        ++elements;
        tmp += pi[i].first;
      }
    }
    ans = max(ans, elements);
  }
  printf("%d", ans);
  return 0;
}