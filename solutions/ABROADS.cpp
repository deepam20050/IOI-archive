// https://www.codechef.com/problems/ABROADS

#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

char t[N];
int x[N];
int y[N];
int from[N];
int to[N];
int p[N];
int size[N];
long long pop[N];
long long psize[N];
long long ans[N];
bool used[N];
set < pair <long long, int> > s;

int find_set(int x) {
  return p[x] == x ? x : (p[x] = find_set(p[x]));
}

void join(int a, int b) {
  int i = find_set(a), j = find_set(b);
  if (i != j) {
    if (size[i] < size[j]) {
      swap(i, j);
    }
    p[j] = i;
    size[i] += size[j];
  }
}

int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", pop + i);
    size[i] = 1;
    p[i] = i;
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", from + i, to + i);
  }
  for (int i = 0; i < q; ++i) {
    cin >> t[i];
    if (t[i] == 'D') {
      scanf("%d", x + i);
      --x[i];
      used[x[i]] = 1;
    } else {
      int val;
      scanf("%d %d", x + i, &val);
      y[i] = pop[x[i]];
      pop[x[i]] = val;
    }
  }
  for (int i = 0; i < m; ++i) {
    if (!used[i]) {
      join(from[i], to[i]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    psize[find_set(i)] += pop[i];
  }
  for (int i = 1; i <= n; ++i) {
    s.insert({psize[i], i});
  }
  for (int i = q - 1; i >= 0; --i) {
    ans[i] = s.rbegin()->first;
    if (t[i] == 'D') {
      int yahan = find_set(from[x[i]]), wahan = find_set(to[x[i]]);
      if (size[yahan] < size[wahan]) {
        swap(yahan, wahan);
      }
      if (wahan == yahan) 
        continue;
      p[wahan] = yahan;
      size[yahan] += size[wahan];
      auto it = s.erase({psize[yahan], yahan});
      psize[yahan] += psize[wahan];
      s.insert({psize[yahan], yahan});
    } else {
      int dad = find_set(x[i]);
      auto it = s.erase({psize[dad], dad});
      psize[dad] -= pop[x[i]];
      pop[x[i]] = y[i];
      psize[dad] += pop[x[i]];
      s.insert({psize[dad], dad});
    }
  }
  for (int i = 0; i < q; ++i) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}