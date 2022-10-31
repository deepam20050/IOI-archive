// http://www.spoj.com/problems/KATHTHI/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const int oo = 1 << 30;

char s[N][N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
deque < pair < int, int > > dq;
int tc;
int n;
int m;
int dist[N][N];

inline void bfs_0_1 () {
	dist[0][0] = 0;
	dq.push_front({0, 0});
	while (!dq.empty()) {
		auto top = dq.front();
		dq.pop_front();
		int x = top.first;
		int y = top.second;
		for (int i = 0; i < 4; ++i) {
			int x0 = x + dx[i];
			int y0 = y + dy[i];
			if (0 <= x0 && x0 < n && 0 <= y0 && y0 < m) {
				bool d = (s[x][y] != s[x0][y0]);
				if (dist[x][y] + d < dist[x0][y0]) {
					dist[x0][y0] = dist[x][y] + d;
					if (d) {
						dq.push_back({x0, y0});
					} else {
						dq.push_front({x0, y0});
					}
				}
			}
		}
	}
}

int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i) {
			scanf("%s", s[i]);
			fill(dist[i], dist[i] + m, oo);
		}
		bfs_0_1();
		printf("%d\n", dist[n - 1][m - 1]);
	}
	return 0;
}