// http://www.spoj.com/problems/MAXSUMSQ/

#include <bits/stdc++.h>

using namespace std;

const long long N = 100010;

long long sum[N];
long long mini[N];
unordered_map <long long, long long> cnt1;
unordered_map <long long, long long> cnt2;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    cnt1.clear();
    cnt2.clear();
    long long n;
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i) {
      long long x;
      scanf("%lld", &x);
      sum[i] = sum[i - 1] + x;
      mini[i] = sum[i];
    }
    long long ans1 = -2e9;
    cnt1[0] = 1;
    for (long long i = 1; i <= n; ++i) {
      cnt2[sum[i] - mini[i - 1]] += cnt1[mini[i - 1]];
      ans1 = max(ans1, sum[i] - mini[i - 1]);
      if (mini[i] > mini[i - 1]) {
        mini[i] = mini[i - 1];
      } else {
        ++cnt1[mini[i]];
      }
    }
    printf("%lld %lld\n", ans1, cnt2[ans1]);
  }
  return 0;
}