// http://codeforces.com/contest/822/problem/C

#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int l[N], r[N], c[N], cost[N];

vector <int> lft[N], rght[N];

int main() {
	int n, x;
	scanf("%d %d", &n, &x);
	memset(cost, -1, sizeof cost);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d %d", l + i, r + i, c + i);
		lft[l[i]].push_back(i);
		rght[r[i]].push_back(i);
	}
	int ans = 2e9 + 10;
	for (int i = N - 1; i >= 1; --i) {
		for (int j : rght[i]) {
			if (r[j] - l[j] + 1 <= x && cost[x - (r[j] - l[j] + 1)] != -1) {
				ans = min(ans, c[j] + cost[x - (r[j] - l[j] + 1)]);
			}
		}
		for (int j : lft[i]) {
			if (cost[r[j] - l[j] + 1] == -1) {
				cost[r[j] - l[j] + 1] = c[j];
			} else {
				cost[r[j] - l[j] + 1] = min(c[j], cost[r[j] - l[j] + 1]);
			}
		}
	}
	if (ans == 2e9 + 10) {
		ans = -1;
	}
	printf("%d", ans);
	return 0;
}