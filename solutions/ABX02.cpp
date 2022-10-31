// https://www.codechef.com/problems/ABX02

#include <bits/stdc++.h>

using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

const long long mod = 1e9 + 7;

long long dp[2][201][201][51][51];
int c[2];
int b[2];
int s[2];

int n;

long long f(bool i, int b0, int b1, int t0, int t1) {
  if (b0 > b[0] || b1 > b[1] || (t0 + t1 > n)) {
    return 0;
  }
  long long &r = dp[i][b0][b1][t0][t1];
  if (t0 + t1 == n) {
    return r = 1;
  }
  if (r != -1) {
    return r;
  }
  r = 0;
  int curr = (!i ? t0 : t1);
  for (int j = 1; j <= s[i] && curr + j <= c[i]; ++j) {
    r += f(i ^ 1, b0 + !i, b1 + i, t0 + (!i ? j : 0), t1 + (i ? j : 0));
    r %= mod;
  }
  return r;
}

int main() {
  int t;
  scan(t);
  while (t--) {
    scan(c[0]);
    scan(c[1]);
    scan(n);
    scan(b[0]);
    scan(b[1]);
    scan(s[0]);
    scan(s[1]);
    memset(dp, -1, sizeof dp);
    printf("%lld\n", (f(0, 0, 0, 0, 0) + f(1, 0, 0, 0, 0))  % mod );
  }
  return 0;
}