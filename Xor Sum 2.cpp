// https://arc098.contest.atcoder.jp/tasks/arc098_b

#include <bits/stdc++.h>

using namespace std;

const int LN = 20;

int last[LN];

int main() {
	int n;
	scanf("%d", &n);
	int prev = 0;
	long long ans = 0;
	memset(last, -1, sizeof last);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		for (int j = 0; j < LN; ++j) {
			if (x & (1 << j)) {
				prev = max(prev, last[j] + 1);
				last[j] = i;
			}
		}
		ans += i - prev + 1;
	}
	printf("%lld\n", ans);
	return 0;
}