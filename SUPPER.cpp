// http://www.spoj.com/problems/SUPPER/

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int arr[N];
int bit[N];
int pos[N];
bool used[N];
queue < pair <int, int> > q;
vector <int> v;
vector <int> at[N];

int n;

void update (int idx, int val) {
  while (idx <= n) {
    bit[idx] = max(bit[idx], val);
    idx += idx & -idx;
  }
}

int query (int idx) {
  int res = 0;
  while (idx) {
    res = max(res, bit[idx]);
    idx -= idx & -idx;
  }
  return res;
}

int main() {
  int currr = 1;
  while (currr <= 10) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", arr + i);
      pos[arr[i]] = i;
    }
    memset(bit, 0, sizeof bit);
    for (int i = 1; i <= n; ++i) {
      at[i].clear();
    }
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
      int cnt = query(pos[i]) + 1;
      mx = max(mx, cnt);
      update(pos[i], cnt);
      at[cnt].emplace_back(pos[i]);
    }
    v.clear();
    while (!q.empty()) {
      q.pop();
    }
    for (int x : at[mx]) {
      q.push({x, mx});
      v.emplace_back(arr[x]);
    }
    memset(used, 0, sizeof used);
    while (!q.empty()) {
      int x = q.front().first;
      int step = q.front().second;
      q.pop();
      for (int e : at[step - 1]) {
        if (e < x && !used[e] && arr[e] < arr[x]) {
          v.emplace_back(arr[e]);
          q.push({e, step - 1});
          used[e] = 1;
        }
      }
    }
    sort(v.begin(), v.end());
    printf("%d\n", (int)v.size());
    for (int x : v) {
      printf("%d ", x);
    }
    puts("");
    ++currr;
  }
  return 0;
}