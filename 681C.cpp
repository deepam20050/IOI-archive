// http://codeforces.com/contest/681/problem/C

#include <bits/stdc++.h>

using namespace std;

string ii = "insert";
string g = "getMin";
string r = "removeMin";

const int N = 1e6 + 10;

int s[N];
int a[N];
priority_queue <int, vector <int>, greater <int> > pq;

int main() {
  ios_base::sync_with_stdio(0);
  int n, j = 0;
  cin >> n;
  while (n--) {
    string t;
    cin >> t;
    if (t[0] == 'i') {
      int x;
      cin >> x;
      s[j] = 1;
      a[j] = x;
      ++j;
      pq.push(x);
    } else if (t[0] == 'g') {
      int x;
      cin >> x;
      while (!pq.empty() && pq.top() < x) {
        s[j++] = 3;
        pq.pop();
      }
      if (pq.empty() || pq.top() != x) {
        s[j] = 1;
        a[j] = x;
        pq.push(x);
        ++j;
      }
      s[j] = 2;
      a[j] = x;
      ++j;
    } else {
      if (pq.empty()) {
        s[j] = 1;
        a[j] = 1;
        ++j;
      } else {
        pq.pop();
      }
      s[j] = 3;
      ++j;
    }
  }
  cout << j << '\n';
  for (int i = 0; i < j; ++i) {
    if (s[i] == 1) {
      cout << ii;
    } else if (s[i] == 2) {
      cout << g;
    } else {
      cout << r;
    }
    if (s[i] != 3) {
      cout << " " << a[i];
    }
    cout << '\n';
  }
  return 0;
}