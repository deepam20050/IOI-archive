// http://codeforces.com/problemset/problem/574/B
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 4010;

pair <int,int> p[N];
int cnt[N];
bool g[N][N];

int main() {
	int n,m;
	scanf("%d %d",&n,&m);

	for (int i = 0; i < m; ++i) {
		scanf("%d %d",&p[i].first,&p[i].second);
		++cnt[p[i].first];
		++cnt[p[i].second];
		g[p[i].first][p[i].second] = 1;
		g[p[i].second][p[i].first] = 1;
	}

	int ans = 1e9;

	for (int i = 0; i < m; ++i) {
		int u = p[i].first, v = p[i].second;
		for (int j = 1; j <= n; ++j) {
			if (j != u && j != v && g[v][j] && g[u][j]) {
				ans = min(ans, cnt[u] + cnt[v] + cnt[j] - 6);
			}
		}
	}

	printf("%d\n",(ans == (int)1e9 ? -1 : ans));

	return 0;
}