// http://codeforces.com/contest/920

#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int pos[N];
int sum[N];
char s[N];

int n;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    pos[x] = i;
  }
  scanf("%s", s);
  for (int i = 1; i <= n; ++i) {
    sum[i] = sum[i - 1] + (s[i - 1] == '1');
  }
  for (int i = 1; i <= n; ++i) {
    int at = pos[i];
    if (abs(sum[i - 1] - sum[at - 1]) != abs(at - i)) {
      return !printf("NO");
    }
  }
  puts("YES");
  return 0;
}