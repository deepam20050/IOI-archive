// http://www.spoj.com/problems/TWENDS/

#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

pair <int, int> dp[N][N];
int a[N];

int n;

pair <int, int> solve (int l, int r) {
	if (l > r) {
		return make_pair(0, 0);
	}
	if (dp[l][r].first != -1) {
		return dp[l][r];
	}
	pair <int, int> p1(a[l], 0), p2(a[r], 0);
	// choose the leftmost
	if (l + 1 <= r) {
		if (a[l + 1] < a[r]) {
			auto temp = solve(l + 1, r - 1);
			p1.first += temp.first;
			p1.second += temp.second + a[r];
		} else {
			auto temp = solve(l + 2, r);
			p1.first += temp.first;
			p1.second += temp.second + a[l + 1];
		}
	} else {
		auto temp = solve(l + 1, r - 1);
		p1.first += temp.first;
		p1.second += temp.second + a[r];
	}
	// choose the rightmost
	if (r - 1 >= l) {
		if (a[l] < a[r - 1]) {
			auto temp = solve(l, r - 2);
			p2.first += temp.first;
			p2.second += temp.second + a[r - 1];
		} else {
			auto temp = solve(l + 1, r - 1);
			p2.first += temp.first;
			p2.second += temp.second + a[l];
		}
	} else {
		auto temp = solve(l + 1, r);
		p2.first += temp.first;
		p2.second += temp.second + a[l];
	}
	return dp[l][r] = max(p1, p2);
}

int main() {
	int m = 1;
	while (scanf("%d", &n) && n != 0) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				dp[i][j].first = dp[i][j].second = -1;
			}
		}
		memset(a, 0, sizeof a);
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
		}
		auto p = solve(0, n - 1);
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n", m, p.first - p.second);
		++m;
	}
	return 0;
}