// http://codeforces.com/problemset/problem/687/A
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int color[N];
vector <int> g[N];
vector <int> a,b;

bool flag = 1;

void dfs(int x, int c) {
	color[x] = c;

	for (const auto &e: g[x]) {
		if (color[e] == -1) {
			dfs(e, c ^ 1);
		} else if (color[e] == c) {
			flag = 0;
			return;
		}
	}
}

int main() {
	int n,m;
	scanf("%d %d",&n,&m);

	for (int i = 0; i < m; ++i) {
		int x,y;
		scanf("%d %d",&x,&y);
		g[x].emplace_back(y);
		g[y].emplace_back(x);
	}

	memset(color,-1,sizeof color);

	for (int i = 1; i <= n; ++i) {
		if (color[i] == -1 && !g[i].empty()) {
			dfs(i,1);
		}
	}

	if (!flag) {
		puts("-1");
		return 0;
	}

	for (int i = 1; i <= n; ++i) {
		if (color[i] == 0)
			a.emplace_back(i);
		else if (color[i] == 1)
			b.emplace_back(i);
	}

	printf("%lu\n",a.size());
	for (const auto &e: a)
		printf("%d ",e);
	putchar('\n');
	printf("%lu\n",b.size());
	for (const auto &e: b) 
		printf("%d ", e);
	putchar('\n');

	return 0;
}