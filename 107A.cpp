// http://codeforces.com/problemset/problem/107/A
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

vector <int> g[N];
int pipe[N][N];
int in[N], out[N];
bool used[N];
vector <int> a,b,c;

int ans, tap;
void dfs(int x, int val) {
	used[x] = 1;
	ans = min(ans,val);

	for (const auto &e: g[x]) {
		if (!used[e]) {
			dfs(e,pipe[x][e]);
		}
	}

	if (g[x].empty())
		tap = x;
}

int main() {
	int n,p;
	scanf("%d %d",&n,&p);

	for (int i = 0; i < p; ++i) {
		int a,b,d;
		scanf("%d %d %d",&a,&b,&d);
		g[a].emplace_back(b);
		pipe[a][b] = d;
		++in[b];
		++out[a];
	}

	if (p == 0) {
		puts("0");
		return 0;
	}

	for (int i = 1; i <= n; ++i) {
		if (in[i] == 0 && out[i] > 0) {
			ans = 1e6;
			dfs(i,1e6);
			a.emplace_back(i);
			b.emplace_back(tap);
			c.emplace_back(ans);
		}
	}

	printf("%d\n",(int)a.size());

	for (int i = 0; i < a.size(); ++i)
		printf("%d %d %d\n",a[i],b[i],c[i]);

	return 0;
}