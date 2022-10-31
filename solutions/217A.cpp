// http://codeforces.com/problemset/problem/217/A
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

bool used[N][N];
int xi[N], yi[N];

int n;

void dfs(int x, int y) {
	used[x][y] = 1;

	for (int i = 0; i < n; ++i) {
		if (xi[i] == x && !used[xi[i]][yi[i]]) {
			dfs(xi[i],yi[i]);
		}
		if (yi[i] == y && !used[xi[i]][yi[i]]) {
			dfs(xi[i],yi[i]);
		}
	}
}

int main() {
	scanf("%d",&n);

	for (int i = 0; i < n; ++i) {
		scanf("%d %d",xi + i, yi + i);
	}

	int ans = 0;

	for (int i = 0; i < n; ++i) {
		if (!used[xi[i]][yi[i]]) {
			++ans;
			dfs(xi[i], yi[i]);
		}
	}
	printf("%d\n",ans - 1);
	return 0;
}