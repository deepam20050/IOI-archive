// http://codeforces.com/contest/799/problem/C
// AC
// Good problem on Two Pointers and good solution by tourist

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int b[N], a[N], best[N];
char ch[N];

int solve(vector < pair <int, int> > v, int lim) {
	sort(v.begin(), v.end());
	int n = v.size();
	if (n < 2) {
		return 0;
	}
	int ans = 0;
	best[0] = 0;
	for (int i = 0; i < n; ++i) {
		best[i + 1] = max(best[i], v[i].second);
	}
	int j = 0;
	for (int i = n - 1; i >= 0; --i) {
		while (j < i && v[i].first + v[j].first <= lim) {
			++j;
		}
		j = min(i, j);
		if (j > 0) {
			ans = max(ans, best[j] + v[i].second);
		}
	}
	return ans;
}

int main() {
	int n, c, d;
	scanf("%d %d %d", &n, &c, &d);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", b + i, a + i);
		ch[i] = getchar();
		while (ch[i] != 'C' && ch[i] != 'D') {
			ch[i] = getchar();
		}
	}
	int ans = 0, a1 = 0, a2 = 0;
	for (int i = 0; i < n; ++i) {
		if (ch[i] == 'C' && a[i] <= c) {
			a1 = max(b[i], a1);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (ch[i] == 'D' && a[i] <= d) {
			a2 = max(b[i], a2);
		}
	}
	if (a1 > 0 && a2 > 0) {
		ans = max(ans, a1 + a2);
	}
	{
		vector < pair <int, int> > x;
		for (int i = 0; i < n; ++i) {
			if (ch[i] == 'C') {
				x.emplace_back(make_pair(a[i], b[i]));
			}
		}
		ans = max(ans, solve(x, c));
	}
	{
		vector < pair <int, int > > x;
		for (int i = 0; i < n; ++i) {
			if (ch[i] == 'D') {
				x.emplace_back(make_pair(a[i], b[i]));
			}
		}
		ans = max(ans, solve(x, d));
	}
	printf("%d\n", ans);
	return 0;
}