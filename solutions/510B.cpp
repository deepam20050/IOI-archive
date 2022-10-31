// http://codeforces.com/problemset/problem/510/B
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 51;

vector <string> v(N);
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
int cnt[N][N];
bool used[N][N];

int n,m;
bool flag = 0;

void dfs(int x, int y, int c, char ch) {
	used[x][y] = 1;
	cnt[x][y] = c;

	for (int i = 0; i < 4; ++i) {
		int xi = dx[i] + x, yi = dy[i] + y;
		if (xi >= 0 && xi < n && yi >= 0 && yi < m) {
			if (v[xi][yi] == ch && !used[xi][yi]) {
				dfs(xi,yi,c + 1,ch);
			} else if (v[xi][yi] == ch && cnt[xi][yi] - cnt[x][y] + 1 >= 4) {
				flag = 1;
				return;
			}
		}
	}
}

int main() {
	
	scanf("%d %d",&n,&m);

	for (int i = 0; i < n; ++i) 
		cin >> v[i];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!used[i][j]) {
				dfs(i,j,1,v[i][j]);
				if (flag) {
					puts("Yes");
					return 0;
				}
			}
		}
	}

	puts("No");

	return 0;
}