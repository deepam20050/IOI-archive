// https://www.codechef.com/MAY17/problems/CHEFSUBA
// AC
// I fucking made it!!!!!!!!

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int z[N], sum[N], pref[N], q[N], dp[N];

int main() {
	int n, k, sz;
	scanf("%d %d %d", &n, &k, &sz);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", z + i);
		sum[i] = sum[i - 1] + z[i];
	}
	{
		for (int i = 1; i <= n; ++i) {
			if (i > k) {
				pref[i] = max(pref[i - 1], sum[i] - sum[i - k]);
			} else {
				pref[i] = sum[i];
			}
		}
	}
	q[0] = pref[n];
	if (k < n) {
		int i = 1, v = n, mx = 0;
		while (i < k && v >= k) {
			int r = k - i;
			dp[r] = sum[r] + sum[n] - sum[v - 1];
			mx = max(mx, dp[r]);
			q[i] = max(mx, max(dp[r], pref[v - 1]));
			++i;
			--v;
		}
		{
			for (int i = 1; i <= n; ++i) {
				dp[i] = max(dp[i - 1], dp[i]);
			}
		}
		mx = 0;
		priority_queue < pair <int, int> , vector < pair <int, int> > > pq;
		while (i < k && v < k) {	
			int r = k - i;
			int x = sum[r] + sum[n] - sum[v - 1];
			while (!pq.empty()) {
				auto top = pq.top();
				if (top.second < v) {
					mx = top.first;
					break;
				} else {
					pq.pop();
				}
			}
			q[i] = max(mx, max(x, max(pref[v - 1], dp[v - 1])));
			pq.push(make_pair(x, r));
			++i;
			--v;
		}
		mx = 0;
		while (i < n) {
			mx = max(mx, sum[v + k - 1] - sum[v - 1]);
			q[i] = max(mx, max(pref[v - 1], dp[v - 1]));
			++i;
			--v;
		}
	}
	string s;
	cin >> s;
	int shift = 0;
	for (const auto &e: s) {
		if (e == '!') {
			++shift;
		} else if (k >= n) {
			printf("%d ", pref[n]);
		} else {
			printf("%d ", q[shift % n]);
		}
	}
	return 0;
}