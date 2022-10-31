// http://codeforces.com/contest/861/problem/B

#include "bits/stdc++.h"

using namespace std;

const int N = 123456, M = 101;

set <int> v;
int a[N];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	while (m--) {
		int x, y;
		scanf("%d %d", &x, &y);
		a[x] = y;
	}
	for (int cnt = 1; cnt < M; ++cnt) {
		bool ok = 1;
		int level = -1;
		int idx = 1;
		for (int f = 1; f < M && ok; ++f) {
			for (int i = 1; i <= cnt; ++i, ++idx) {
				if (a[idx] != 0 && a[idx] != f) {
					ok = 0;
					break;
				}
				if (idx == n) {
					level = f;
				} 
			}
		}
		if (ok) {
			v.insert(level);
		}
	}
	// printf("%d\n", (int)v.size());
	v.size() == 1 ? printf("%d", *(v.begin())) : puts("-1");
	return 0;
}