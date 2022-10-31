// http://codeforces.com/contest/760/problem/C

#include "bits/stdc++.h"

using namespace std;

const int N = 200010;

int p[N];
bool used[N];

void dfs(int x) {
	used[x] = 1;
	if (!used[p[x]]) {
		dfs(p[x]);
	}
}

int main() {
	int n, ones = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", p + i);
	}
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		ones += x;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			dfs(i);
			++ans;
		}
	}
	if (ans == 1) {
		ans = 0;
	}
	if (ones % 2 == 0) {
		++ans;
	}
	printf("%d", ans);
	return 0;
}