// https://dmoj.ca/problem/ccc09s4

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <cctype>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <vector>
#include <utility>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

const int N = 5010;

int d[N], place[N], cost[N];
priority_queue < pair <int, int> > pq;
vector < pair <int, int > > g[N];

int main() {
  int n, t;
  scan(n);
  scan(t);
  fill(d + 1, d + n + 1, 1 << 22);
  while (t--) {
    int x, y, c;
    scan(x);
    scan(y);
    scan(c);
    g[x].push_back({y, c});
    g[y].push_back({x, c});
  }
  int k;
  scan(k);
  for (int i = 0; i < k; ++i) {
    scan(place[i]);
    scan(cost[i]);
  }
  int from;
  scan(from);
  d[from] = 0;
  pq.push({0, from});
  while (!pq.empty()) {
    int from = pq.top().second;
    pq.pop();
    for (auto &temp : g[from]) {
      int to = temp.first;
      if (d[to] > d[from] + temp.second) {
        d[to] = d[from] + temp.second;
        pq.push({-d[to], to});
      }
    }
  }
  int mini = 1 << 22;
  for (int i = 0; i < k; ++i) {
    mini = min(mini, d[place[i]] + cost[i]);
  }
  printf("%d\n", mini);
  return 0;
}