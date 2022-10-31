// http://www.spoj.com/problems/MREPLBRC/

#include <bits/stdc++.h>

using namespace std;

const int N = 201;
const long long mod = 100000;

long long dp[N][N];
char s[N];

int n;
bool yes;

int get(int left, int i) {
  int valid = 0;
  if(s[left]=='(' && s[i]==')') valid=1;
  else if(s[left]=='{' && s[i]=='}') valid=1;
  else if(s[left]=='[' && s[i]==']') valid=1;
  else if(s[left]=='?' && s[i]==')') valid=1;
  else if(s[left]=='?' && s[i]=='}') valid=1;
  else if(s[left]=='?' && s[i]==']') valid=1;
  else if(s[left]=='(' && s[i]=='?') valid=1;
  else if(s[left]=='{' && s[i]=='?') valid=1;
  else if(s[left]=='[' && s[i]=='?') valid=1;
  else if(s[left]=='?' && s[i]=='?') valid=3;
  return valid;
}

long long solve(int l, int r) {
  if (r < l) {
    return 1;
  }
  if (dp[l][r] != -1) {
    return dp[l][r];
  }
  dp[l][r] = 0;
  for (int i = l + 1; i <= r; ++i) {
    dp[l][r] += (get(l, i) * solve(l + 1, i - 1) * solve(i + 1, r));
    if (dp[l][r] >= mod) {
      yes = 1;
      dp[l][r] %= mod;
    }
  }
  return dp[l][r];
}

int main() {
  scanf("%d", &n);
  scanf("%s", s);
  memset(dp, -1, sizeof dp);
  long long ans = solve(0, n - 1);
  if (!yes) {
    return !printf("%lld", ans);
  }
  printf("%05lld\n", ans);
  return 0;
}