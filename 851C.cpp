// http://codeforces.com/contest/851/problem/C

#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 1;

int arr[N][5];
bool bad[N];
queue <int> q;
vector <int> ans;

int check (int a, int b, int c) {
  int sum = 0;
  for (int i = 0; i < 5; ++i) {
    sum += (arr[b][i] - arr[a][i]) * (arr[c][i] - arr[a][i]);
  }
  return sum;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 5; ++j) {
      scanf("%d", arr[i] + j);
    }
    q.push(i);
  }
  while (!q.empty()) {
    if (q.size() > 2) {
      int a = q.front(); q.pop();
      int b = q.front(); q.pop();
      int c = q.front(); q.pop();
      if (check(a, b, c) <= 0) {
        bad[b] = 1;
        bad[c] = 1;
        q.push(a);
      } else if (check(b, c, a) <= 0) {
        bad[c] = 1;
        bad[a] = 1;
        q.push(b);
      } else if (check(c, a, b) <= 0) {
        bad[a] = 1;
        bad[b] = 1;
        q.push(c);
      } else {
        bad[a] = 1;
        bad[b] = 1;
        bad[c] = 1;
      }
    } else {
      int who = q.front();
      q.pop();
      bool flag = 1;
      for (int i = 0; i < n; ++i) {
        if (i == who) {
          continue;
        }
        for (int j = 0; j < n; ++j) {
          if (i == j || who == j) {
            continue;
          }
          if (check(who, i, j) > 0) {
            flag = 0;
            break;
          }
        }
      }
      if (flag) {
        ans.emplace_back(who);
      } else {
        bad[who] = 1;
      }
    }
  }
  sort(ans.begin(), ans.end());
  printf("%d\n", ans.size());
  for (int x : ans) {
    printf("%d ", x + 1);
  }
  return 0;
}