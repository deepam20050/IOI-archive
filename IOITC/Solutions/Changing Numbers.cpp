#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int arr[N];
int brr[N];
int p[N];
int sz[N];
bool used[N];
int tc;
int n;
int k;

inline void clear () {
	for (int i = 1; i <= n; ++i) {
		p[i] = i;
		sz[i] = 1;
		used[i] = 0;
	}
}

inline int find_parent (int x) {
	return p[x] == x ? x : p[x] = find_parent(p[x]);
}

inline void join (int x, int y) {
	x = find_parent(x);
	y = find_parent(y);
	if (x == y) {
		return;
	}
	if (sz[x] < sz[y]) {
		swap(x, y);
	}
	sz[x] += sz[y];
	p[y] = x;
}

int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &n, &k);
		clear();
		for (int i = 1; i <= n; ++i) {
			scanf("%d", arr + i);
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", brr + i);
			join(arr[i], brr[i]);
		}
	}
	return 0;
}