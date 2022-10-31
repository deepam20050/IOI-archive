#include <bits/stdc++.h>

using namespace std;

stack < int > st;

int main() {
  int n;
  scanf("%d", &n);
  int ans = 0;
  while (n--) {
    int y, x;
    scanf("%d %d", &y, &x);
    while (!st.empty() && st.top() > x) {
      st.pop();
    }
    ans += st.empty() || (!st.empty() && st.top() < x);
    st.push(x);
  }
  printf("%d\n", ans);
  return 0;
}