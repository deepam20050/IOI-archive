// http://codeforces.com/contest/761/problem/C

#include "bits/stdc++.h"

using namespace std;

const int N = 50, oo = 1e8;

char s[N][N];
bool there[10];
int c[N][10];

int type(char ch) {
	if (isalpha(ch)) {
		return 1;
	}
	if (isdigit(ch)) {
		return 2;
	}
	return 3;
}

int main() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 10; ++j) {
			c[i][j] = oo;
		}
	}
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", s[i]);
		for (int j = 1; j <= m; ++j) {
			c[i][type(s[i][j - 1])] = min(c[i][type(s[i][j - 1])], min(j - 1, m - j + 1));
		}
	}
	int ans = oo;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (j == i) {
				continue;
			}
			for (int k = 0; k < n; ++k) {
				if (k == i || k == j) {
					continue;
				}
				int p = c[i][1] + c[j][2] + c[k][3];
				int q = c[i][1] + c[j][3] + c[k][2];
				int r = c[i][2] + c[j][1] + c[k][3];
				int s = c[i][2] + c[j][3] + c[k][1];
				int t = c[i][3] + c[j][1] + c[k][2];
				int u = c[i][3] + c[j][2] + c[k][1];
				ans = min(ans, min(p, min(q, min(r, min(s, min(t, u))))));
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}