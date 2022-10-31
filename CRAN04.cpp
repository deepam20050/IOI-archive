// http://www.spoj.com/problems/CRAN04/

#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

long long cnt[N];
char s[N];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d %d", &n, &k);
		scanf("%s", s);
		memset(cnt, 0, sizeof cnt);
		++cnt[0];
		long long res = 0;
		int ones = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '1') {
				++ones;
			}
			if (ones >= k) {
				res += cnt[ones - k];
			}
			++cnt[ones]; 
		}
		printf("%lld\n", res);
	}
	return 0;
}