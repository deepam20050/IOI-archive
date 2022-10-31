// http://codeforces.com/contest/667/problem/B

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  long long mx = *max_element(a, a + n);
  long long sum = accumulate(a, a + n, 0LL);
  printf("%lld", mx - (sum - mx) + 1);
	return 0;
}

