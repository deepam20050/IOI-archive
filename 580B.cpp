// http://codeforces.com/problemset/problem/580/B
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 100000;

pair<long long,long long> p[N];
long long sum[N+1];
int n;

int main() {
	long d;
	scanf("%d %ld",&n,&d);

	for (int i = 0; i < n; ++i) {
		scanf("%lld %lld",&p[i].first, &p[i].second);
	}
	sort(p,p+n);

	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i-1] + p[i-1].second;
	}
	long long ans = -1;
	int j = 1;
	for (int i = 0; i < n; ++i) {
		while ((j < n) && (p[i].first + d > p[j].first)) {
			++j;
		}
		ans = max(ans, sum[j] - sum[i]);
	}

	printf("%lld\n",ans);

	return 0;
}