// http://codeforces.com/problemset/problem/4/D

#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

int dp[N], peche[N];
vector < pair <int, int> > p;
map < pair <int, int> , int > mp;

int main() {
	int sz, w, h;
	scanf("%d %d %d", &sz, &w, &h);
	for (int i = 0; i < sz; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		if (w < x && h < y) {
			mp[{x, y}] = i + 1;
			p.push_back({x, y});
		}
		dp[i] = 1;
		peche[i] = -1;
	}
	sort(p.begin(), p.end(), greater < pair <int, int> > ());
	int n = p.size();
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (p[i].first < p[j].first && p[i].second < p[j].second) {
				if (dp[j] + 1 > dp[i]) {
					peche[i] = j;
					dp[i] = dp[j] + 1;
				}
			}
		}
	}
	int ans = 0, idx = 0;
	for (int i = 0; i < n; ++i) {
		if (dp[i] > ans) {
			ans = dp[i];
			idx = i;
		}
	}
	printf("%d\n", ans);
	while (idx >= 0 && ans) {
		printf("%d ", mp[{p[idx].first, p[idx].second}]);
		idx = peche[idx];
	}
	return 0;
}