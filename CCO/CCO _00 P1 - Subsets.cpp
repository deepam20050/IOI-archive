// http://wcipeg.com/problem/ccc00s2p1

#include <bits/stdc++.h>

using namespace std;

const int N = 30;

bool used[N];
bool mention[N];
bool a[N][N];
vector <int> g[N];

void dfs(int x) {
  used[x] = 1;
  for (int to : g[x]) {
    if (!used[to]) {
      dfs(to);
    }
    for (int i = 0; i < N; ++i) {
      if (a[to][i]) {
        a[x][i] = 1;
      }
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    char c;
    string s;
    char d;
    cin >> c >> s >> d;
    mention[c - 'A'] = 1;
    if ('a' <= d && d <= 'z') {
      a[c - 'A'][d - 'a'] = 1;
    } else {
      g[c - 'A'].push_back(d - 'A');
      mention[d - 'A'] = 1;
    }
  }
  for (int i = 0; i < 26; ++i) {
    if (!used[i]) {
      dfs(i);
    }
  }
  for (int i = 0; i < N; ++i) {
    if (!mention[i]) {
      continue;
    }
    printf("%c = {", i + 'A');
    string s;
    for (int j = 0; j < N; ++j) {
      if (a[i][j]) {
        s += j + 'a';
        s += ',';
      }
    }
    if (!s.empty()) {
      s.pop_back();
    }
    s += '}';
    cout << s << '\n';
  }
  return 0;
}