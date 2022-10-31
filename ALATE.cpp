// https://www.codechef.com/problems/ALATE
// 1 + 1/2 + 1/3 + 1/4 + ... + 1/n = O(log n)

#include "bits/stdc++.h"

using namespace std;

const int N = 100001;
const long long mod = 1000000007;

vector <int> divisors[N];
long long a[N];
long long ans[N];

int main() {
	for (int i = 1; i < N; ++i) {
		for (int j = i; j < N; j += i) {
			divisors[j].emplace_back(i);
		}
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, q;
		scanf("%d %d", &n, &q);
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", a + i);
			a[i] = a[i] * a[i] % mod;
		}
		for (int i = 1; i <= n; ++i) {
			ans[i] = 0LL;
			for (int j = i; j <= n; j += i) {
				ans[i] += a[j];
			}
		}
		while (q--) {
			int op, x;
			scanf("%d %d", &op, &x);
			if (op == 1) {
				printf("%lld\n", ans[x] % mod);
			} else {
				long long y;
				scanf("%lld", &y);
				y = y * y % mod;
				for (int idx : divisors[x]) {
					ans[idx] += (y - a[x]) % mod;
				}
				a[x] = y;
			}
		}
	}
	return 0;
}