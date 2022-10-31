// http://codeforces.com/contest/797/problem/C
// Nice problem

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

char s[N];
char t[N];
bool ok[N];
stack <char> st;

int main() {
  scanf("%s", s);
  int n = strlen(s);
  t[n] = 'z' + 1;
  t[n - 1] = s[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    t[i] = min(s[i], t[i + 1]);
  }
  for (int i = 0; i < n; ++i) {
    st.push(s[i]);
    while (!st.empty() && st.top() <= t[i + 1]) {
      printf("%c", st.top());
      st.pop();
    }
  }
  while (!st.empty()) {
    printf("%c", st.top());
    st.pop();
  }
  return 0;
}