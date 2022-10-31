// http://codeforces.com/contest/767/problem/C

#include "bits/stdc++.h"

using namespace std;

const int N = 1000010;

vector <int> g[N];
int who[N];
int sum[N];
int a[N];

long long sm;
int n;

void dfs(int x) {
	sum[x] += a[x];
	int last1 = -1, last2 = -1;
	for (int to: g[x]) {
		dfs(to);
		sum[x] += sum[to];
		if (who[to] != -1) {
			last2 = last1;
			last1 = who[to];
		}
	}
	if (last2 != -1) {
		printf("%d %d", last1, last2);
		exit(0);
	}
	if (x != g[0][0] && last1 != -1 && sum[x] == sm + sm) {
		printf("%d %d", x, last1);
		exit(0);
	}
	if (sum[x] == sm) {
		who[x] = x;
	} else {
		who[x] = last1;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d %d", &x, a + i);
		g[x].emplace_back(i);
		who[i] = -1;
		sm += a[i];
	}
	if (sm % 3) {
		return !printf("-1");
	}
	sm /= 3;
	dfs(g[0][0]);
	puts("-1");
	return 0;
}