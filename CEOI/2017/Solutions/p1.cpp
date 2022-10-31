#include <bits/stdc++.h>

using namespace std;

int n, m, k, y[100005][2], d[100005], par[100005], pp[100005], up[100005], dw[100005], ta, tb;
vector< int > x[100005], z[100005], za[100005], zb[100005];
char ans[100005];
bool v[100005];

int find(int a) {
	if (par[a] == a)
		return a;
	return par[a] = find(par[a]);
}

int ff(int a) {
	if (pp[a] == a)
		return a;
	return pp[a] = ff(pp[a]);
}

int dfs1(int a, int b, int c) {
	int mi = d[a] = b;
	par[a] = a;
	for (int i = 0; i < x[a].size(); i++)
		if (x[a][i] != c) {
			int to = y[x[a][i]][0];
			if (to == a)
				to = y[x[a][i]][1];
			if (d[to])
				mi = min(mi, d[to]);
			else {
				int re = dfs1(to, b + 1, x[a][i]);
				mi = min(mi, re);
				if (re == b + 1)
					ans[x[a][i]] = 'D';
				else
					par[to] = a;
			}
		}
	return mi;
}

void dfs2(int a, int b) {
	pp[a] = a;
	for (int i = 0; i < z[a].size(); i++)
		if (z[a][i] != b) {
			dfs2(z[a][i], a);
			pp[ff(z[a][i])] = a;
		}
	v[a] = 1;
	for (int i = 0; i < za[a].size(); i++)
		if (v[za[a][i]]) {
			up[ff(za[a][i])]--;
			dw[pp[za[a][i]]]--;
		}
}

void dfs3(int a, int b) {
	v[a] = 0;
	for (int i = 0; i < z[a].size(); i++)
		if (z[a][i] != b) {
			dfs3(z[a][i], a);
			if (up[z[a][i]])
				ans[zb[a][i]] = (a == par[y[zb[a][i]][1]] ? 'R' : 'L');
			else if (dw[z[a][i]])
				ans[zb[a][i]] = (a == par[y[zb[a][i]][1]] ? 'L' : 'R');
			else
				ans[zb[a][i]] = 'B';
			up[a] += up[z[a][i]];
			dw[a] += dw[z[a][i]];
		}
}

int main() {
	scanf("%d%d", &n, &m);
	memset(ans, 'B', m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", y[i], y[i] + 1);
		for (int j = 0; j < 2; j++)
			x[y[i][j]].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		if (!d[i])
			dfs1(i, 1, -1);
	for (int i = 0; i < m; i++)
		if (ans[i] == 'D') {
			z[find(y[i][0])].push_back(find(y[i][1]));
			zb[par[y[i][0]]].push_back(i);
			z[par[y[i][1]]].push_back(par[y[i][0]]);
			zb[par[y[i][1]]].push_back(i);
		}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d%d", &ta, &tb);
		ta = find(ta), tb = find(tb);
		if (ta != tb) {
			za[ta].push_back(tb);
			za[tb].push_back(ta);
			up[ta]++;
			dw[tb]++;
		}
	}
	for (int i = 1; i <= n; i++)
		if (i == find(i) && !pp[i])
			dfs2(i, 0);
	for (int i = 1; i <= n; i++)
		if (i == par[i] && v[i])
			dfs3(i, 0);
	printf("%s\n", ans);
	return 0;
}