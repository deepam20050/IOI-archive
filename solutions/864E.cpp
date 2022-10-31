// http://codeforces.com/problemset/problem/864/E

#include <bits/stdc++.h>

using namespace std;

const int N = 101, M = 2048;

pair <int, pair <int, int>> a[N];
int dp[N][M];
bool yahan[N][M];
int agla[N][M];
map <pair <int, pair <int, int>>, stack <int>> mp;

int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d %d", &a[i].second.first, &a[i].first, &a[i].second.second);
		mp[{a[i].first, {a[i].second.first, a[i].second.second}}].push(i);
	}
	sort(a, a + n);
	for (int i = M - 1; i >= 0; --i) {
		for (int j = n - 1; j >= 0; --j) {
			int mx1 = -1, mx2 = -1, kahan1 = -1, kahan2 = -1;
			for (int k = j + 1; k < n; ++k) {
				if (i + a[j].second.first < a[j].first && dp[k][i + a[j].second.first] + a[j].second.second > mx1) {
					mx1 = dp[k][i + a[j].second.first] + a[j].second.second;
					kahan1 = k;
				}
				if (dp[k][i] > mx2) {
					mx2 = dp[k][i];
					kahan2 = k;
				}
			}
			if (mx1 > mx2) {
				dp[j][i] = mx1;
				agla[j][i] = kahan1;
				yahan[j][i] = 1;
			} else {
				dp[j][i] = mx2;
				agla[j][i] = kahan2;
			}
			if (i + a[j].second.first < a[j].first && a[j].second.second > dp[j][i]) {
				dp[j][i] = a[j].second.second;
				agla[j][i] = -1;
				yahan[j][i] = 1;
			}
		}
	}
	if (dp[0][0] < 0) {
		dp[0][0] = 0;
	}
	printf("%d\n", dp[0][0]);
	int i = 0, j = 0;
	vector <int> v;
	while (i != -1) {
		if (yahan[i][j]) {
			v.emplace_back(i);
		}
		int temp = i;
		i = agla[i][j];
		j += (yahan[temp][j] ? a[temp].second.first : 0);
	}
	printf("%d\n", (int) v.size());
	for (int i: v) {
		printf("%d ", 1 + mp[{a[i].first, {a[i].second.first, a[i].second.second}}].top());
		mp[{a[i].first, {a[i].second.first, a[i].second.second}}].pop();
	}
	return 0;
}