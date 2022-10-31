// https://www.codechef.com/LOCJUL17/problems/MAAFIA

#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 10;
 
vector <int> g[N];
bool used[N], st[N];
int don[N];
 
int n, m, k;
 
bool F(int dd) {
	memset(used, 0, sizeof used);
	for (int i = 0; i < k; ++i) {
		memset(st, 0, sizeof st);
		queue < pair <int, int> > q;
		q.push({don[i], 0});
		while (!q.empty()) {
			int x = q.front().first, dist = q.front().second;
			q.pop();
			if (used[x]) {
				return 0;
			}
			st[x] = 1;
			used[x] = 1;
			if (dist + 1 > dd) {
				continue;
			}
			for (int to: g[x]) {
				if (used[to] && !st[to]) {
					return 0;
				} else if (!used[to]) {
					q.push({to, dist + 1});
				}
			}
		}
	}
	return 1;
}
 
int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i = 0; i < k; ++i) {
		scanf("%d", don + i);
	}
	int l = 0, r = N;
	for (int i = 0; i < 50; ++i) {
		int mid = (l + r) >> 1;
		if (F(mid)) {
			l = mid;
		} else {
			r = mid;
		}
	}
	int ans = accumulate(used, used + N, 0);
	printf("%d\n", ans);
	return 0;
} 
