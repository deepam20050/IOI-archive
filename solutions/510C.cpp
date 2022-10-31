// http://codeforces.com/problemset/problem/510/C

#include <bits/stdc++.h>

using namespace std;

const int N = 122;

string s[N];
bool eq[N];
vector <int> g[30];
int used[N];
string ans;

void dfs(int x) {
  used[x] = 1;
  for (int to : g[x]) {
    if (!used[to]) {
      dfs(to);
    } else if (used[to] == 1) {
      puts("Impossible");
      exit(0);
    } 
  }
  used[x] = 2;
  ans += x + 'a';
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  fill(eq, eq + N, 1);
  for (int j = 0; j < N; ++j) {
    for (int i = 1; i < n; ++i) {
      if (s[i].size() > j && eq[i]) {
        if (s[i - 1].size() > j) {
          if (s[i - 1][j] != s[i][j]) {
            g[s[i - 1][j] - 'a'].push_back(s[i][j] - 'a');
            eq[i] = 0;
          } else {
            eq[i] = 1;
          }
        } else {
          eq[i] = 0;
        } 
      } else if (eq[i]) {
        puts("Impossible");
        return 0;
      } else {
        eq[i] = 0;
      }
    }
  }
  for (int i = 0; i < 26; ++i) {
    if (!used[i]) {
      dfs(i);
    }
  }
  reverse(ans.begin(), ans.end());
  cout << ans;
  return 0;
}