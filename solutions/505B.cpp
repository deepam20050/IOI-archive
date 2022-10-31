// http://codeforces.com/problemset/problem/505/B
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 101;

map < pair <int,int>, set <int> > mp;
vector <int> g[N];
bool used[N];

int u,v,there;
void dfs(int x, int c) {
	if (x == v) {
		there = 1;
	}
	used[x] = 1;

	for (const auto &e: g[x]) {
		if (!used[e] && mp[make_pair(e,x)].find(c) != mp[make_pair(e,x)].end()) {
			dfs(e,c);
		}
	}
}

int main() {
	int n,m;
	scanf("%d %d",&n,&m);

	for (int i = 0,x,y,c; i < m; ++i) {
		scanf("%d %d %d",&x, &y, &c);
		mp[make_pair(x,y)].insert(c);
		mp[make_pair(y,x)].insert(c);
		g[x].emplace_back(y);
		g[y].emplace_back(x);
	}

	int q;
	scanf("%d",&q);

	while (q--) {
		scanf("%d %d",&u,&v);
		int ans = 0;
		for (int c = 1; c <= m; ++c) {
			there = 0;
			dfs(u,c);
			if (there) {
				++ans;
			}
			memset(used,0,sizeof used);
		}
		printf("%d\n",ans);
	}

	return 0;
}