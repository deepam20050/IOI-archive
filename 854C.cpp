// http://codeforces.com/problemset/problem/854/C

#include "bits/stdc++.h"

using namespace std;
using pi = pair <int, int>;

const int N = 300010;

int c[N], ans[N];
priority_queue < pi, vector <pi>> pq;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= k; ++i) {
		scanf("%d", c + i);
		pq.push({c[i], i});
	}
	long long res = 0;
	for (int i = k + 1; i <= n + k; ++i) {
		if (i <= n) {
			scanf("%d", c + i);
			pq.push({c[i], i});
		}
		auto top = pq.top();
		pq.pop();
		res += (i - top.second) * (long long)top.first;
		ans[top.second] = i;
	}
	printf("%lld\n", res);
	for (int i = 1; i <= n; ++i) {
		printf("%d ", ans[i]);
	}
	return 0;
}