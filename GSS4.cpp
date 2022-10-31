// https://www.spoj.com/problems/GSS4/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long arr[N];
long long sum[N << 2];
long long mx[N << 2];
int n;
int q;

inline void join (int node) {
	sum[node] = sum[node << 1] + sum[node << 1 | 1];
	mx[node] = max(mx[node << 1], mx[node << 1 | 1]);
}

void build (int node, int l, int r) {
	if (l == r) {
		sum[node] = arr[l];
		mx[node] = arr[l];
		return;
	}
	int m = l + r >> 1;
	build(node << 1, l, m);
	build(node << 1 | 1, m + 1, r);
	join(node);
}

void update (int node, int l, int r, int x, int y) {
	if (l == r) {
		arr[l] = sqrt(arr[l]);
		sum[node] = arr[l];
		mx[node] = arr[l];
		return;
	}
	int m = l + r >> 1;
	if (x <= m && mx[node << 1] > 1) {
		update(node << 1, l, m, x, y);
	}
	if (y > m && mx[node << 1 | 1] > 1) {
		update(node << 1 | 1, m + 1, r, x, y);
	}
	join(node);
}

long long query (int node, int l, int r, int x, int y) {
	if (x <= l && r <= y) {
		return sum[node];
	}
	long long ret = 0;
	int m = l + r >> 1;
	if (x <= m) {
		ret += query(node << 1, l, m, x, y);
	}
	if (y > m) {
		ret += query(node << 1 | 1, m + 1, r, x, y);
	}
	return ret;
}

int main() {
	int tc = 0;
	while (scanf("%d", &n) != EOF) {
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", arr + i);
		}
		build(1, 1, n);
		scanf("%d", &q);
		printf("Case #%d:\n", ++tc);
		while (q--) {
			int op, x, y;
			scanf("%d %d %d", &op, &x, &y);
			if (x > y) {
				swap(x, y);
			}
			if (!op) {
				update(1, 1, n, x, y);
			} else {
				printf("%lld\n", query(1, 1, n, x, y));
			}
		}
		puts("");
	}
	return 0;
}