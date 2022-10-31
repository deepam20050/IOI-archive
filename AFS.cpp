// https://www.spoj.com/problems/AFS/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 1;

long long a[N];
long long sum[N];

int main() {
	for (int i = 1; i < N; ++i) {
		for (int j = i + i; j < N; j += i) {
			sum[j] += 1LL * i;
		}
	}
	a[0] = 0;
	a[1] = 0;
	for (int i = 2; i < N; ++i) {
		a[i] = a[i - 1] + sum[i];
	}
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", a[n]);
	}
	return 0;
}