// http://codeforces.com/problemset/problem/601/A
// AC

#include <bits/stdc++.h>

using namespace std;
using pi = pair <int,int>;

const int N = 410, INF = 1e6;

bool train[N][N], bus[N][N];
int dt[N], db[N];
priority_queue <pi, vector <pi>, greater <pi>> p1;

int main() {
	int n,m;
	scanf("%d %d",&n,&m);

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) 
			bus[i][j] = 1;
	
	for (int i = 2; i <= n; ++i)
			dt[i] = db[i] = INF;

	for (int i = 0; i < m; ++i) {
		int a,b;
		scanf("%d %d",&a,&b);
		train[a][b] = train[b][a] = 1;
		bus[a][b] = bus[b][a] = 0;
	}

	p1.push({0,1});

	while (!p1.empty()) {
		int w = p1.top().first, x = p1.top().second; p1.pop();
		for (int i = 1; i <= n; ++i) {
			if (i == x || !train[x][i]) continue;
			if (dt[i] > w + 1) {
				dt[i] = w + 1;
				p1.push({dt[i], i});
			}
		}
	}

	p1.push({0,1});

	while (!p1.empty()) {
		while (!p1.empty() && p1.top().second != 1 && dt[p1.top().second] == p1.top().first) 
			p1.pop();
		if (p1.empty()) break;
		int w = p1.top().first, x = p1.top().second; p1.pop();
		for (int i = 1; i <= n; ++i) {
			if (i == x || !bus[i][x]) continue;
			if (db[i] > w + 1) {
				db[i] = w + 1;
				p1.push({db[i], i});
			}
		}
	}

	if (dt[n] == INF || db[n] == INF) {
		puts("-1");
		return 0;
	}

	printf("%d\n", max(dt[n], db[n]));

	return 0;
}