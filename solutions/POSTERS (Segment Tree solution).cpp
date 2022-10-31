// https://www.spoj.com/problems/POSTERS/
// Easy solution with segment trees :)

#include <bits/stdc++.h>

using namespace std;

const int N = 4e4 + 5;

int arr[N << 1];
int l[N];
int r[N];
bool yes[N];
int lazy[N << 2];
int tc;
int n;
int m;
int ans;
inline void push (int node) {
	if (lazy[node]) {
		lazy[node << 1] = lazy[node];
		lazy[node << 1 | 1] = lazy[node];
	}
	lazy[node] = 0;
}

void update (int node, int l, int r, int x, int y, int color) {
	if (x <= l && r <= y) {
		lazy[node] = color;
		return;
	}
	int m = l + r >> 1;
	push(node);
	if (x <= m) {
		update(node << 1, l, m, x, y, color);
	}
	if (y > m) {
		update(node << 1 | 1, m + 1, r, x, y, color);
	}
}

void cnt (int node, int l, int r) {
	if (lazy[node]) {
		ans += !yes[lazy[node]];
		yes[lazy[node]] = 1;
		return;
	}
	int m = l + r >> 1;
	if (l == r) {
		return;
	}
	cnt(node << 1, l, m);
	cnt(node << 1 | 1, m + 1, r);
}

inline void clear () {
	memset(yes, 0, sizeof yes);
	memset(lazy, 0, sizeof lazy);
	ans = 0;
	m = 0;
	ans = 0;
}

int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		clear();
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", l + i, r + i);
			arr[++m] = l[i];
			arr[++m] = r[i];
		}
		sort(arr, arr + m + 1);
		for (int i = 1; i <= n; ++i) {
			int x = lower_bound(arr, arr + m + 1, l[i - 1]) - arr;
			int y = upper_bound(arr, arr + m + 1, r[i - 1]) - arr - 1;
			update(1, 1, m, x, y, i);
		}
		cnt(1, 1, m);
		printf("%d\n", ans);
	}
	return 0;
}