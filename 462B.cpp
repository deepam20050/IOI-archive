// http://codeforces.com/problemset/problem/462/B
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

char s[N];
long long cnt[26];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  scanf("%s", s);
  for (int i = 0; i < n; ++i) {
    ++cnt[s[i] - 'A'];
  }
  sort(cnt, cnt + 26, greater <int> ());
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    if (k < cnt[i]) {
      ans += (long long)k * k;
      break;
    } else {
      ans += (long long)cnt[i] * cnt[i];
      k -= cnt[i];
    }
    //cout << cnt[i] << " " ;
  }
  printf("%lld\n", ans);
  return 0;
}

