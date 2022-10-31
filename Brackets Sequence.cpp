// http://acm.timus.ru/problem.aspx?space=1&num=1183

#include <bits/stdc++.h>

using namespace std;
using pi = pair <int, int>;

const int N = 101;

string a[N];
char s[N];
int dp[N][N];
int at[N][N];
vector <pi> g[N][N];

int F(int l, int r) {
  if (l > r) {
    return 0;
  }
  if (dp[l][r] != -1) {
    return dp[l][r];
  }
  pi x = {-1, -1};
  pi y = {-1, -1};
  if (s[l] == ')' || s[l] == ']') {
    x = {l + 1, r};
    at[l][r] = l;
    g[l][r].push_back(x);
    return dp[l][r] = 1 + F(l + 1, r);
  }
  char close = s[l] == '(' ? ')' : ']';
  int &ref = dp[l][r];
  ref = 1 + F(l + 1, r);
  x = {l + 1, r};
  at[l][r] = l + 1;
  for (int i = l + 1; i <= r; ++i) {
    if (s[i] == close) {
      int val = F(l + 1, i - 1) + F(i + 1, r);
      if (val < ref) {
        ref = val;
        x = {l + 1, i - 1};
        y = {i + 1, r};
        at[l][r] = -1;
      }
    } else {
      int val = 1 + F(l + 1, i) + F(i + 1, r);
      if (val < ref) {
        ref = val;
        x = {l + 1, i};
        y = {i + 1, r};
        at[l][r] = i + 1;
      }
    }
  }
  g[l][r].emplace_back(x);
  g[l][r].emplace_back(y);
  return ref;
}

void dfs(int x, int y) {
  if (at[x][y] != -1) {
    char c = '-';
    if (s[x] == '(') {
      c = ')';
    } else if (s[x] == ')') {
      c = '(';
    } else if (s[x] == '[') {
      c = ']';
    } else if (s[x] == ']') {
      c = '[';
    }
    a[at[x][y]] += c;
  }
  for (pi &to : g[x][y]) {
    int x0 = to.first;
    int y0 = to.second;
    if (x0 != -1 && y0 != -1) {
      dfs(x0, y0);
    }
  }
}

int main() {
  scanf("%s", s);
  int n = strlen(s);
  memset(dp, -1, sizeof dp);
  memset(at, -1, sizeof at);
  for (int i = 0; i < n; ++i) {
    dp[i][i] = 1;
    if (s[i] == '(' || s[i] == '[') {
      at[i][i] = i + 1;
    } else {
      at[i][i] = i;
    }
  }
  F(0, n - 1);
  dfs(0, n - 1);
  for (int i = 0; i <= n; ++i) {
    if (i == n) {
      cout << a[i];
    } else {
      cout << a[i] << s[i];
    }
  }
  return 0;
}