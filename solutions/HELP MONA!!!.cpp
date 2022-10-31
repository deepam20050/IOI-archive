// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/help-mona/description/

#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;

int arr[N];
int t[N << 2];
int n;
int q;

void build (int node, int l, int r) {
	if (l == r) {
		t[node] = arr[l];
		return;
	}
	int m = l + r >> 1;
	build(node << 1, l, m);
	build(node << 1 | 1, m + 1, r);
	t[node] = t[node << 1] + t[node << 1 | 1];
}

void update (int node, int l, int r, int x) {
	if (l == r) {
		t[node] = 1 - arr[x];
		arr[x] = 1 - arr[x];
		return;
	}
	int m = l + r >> 1;
	if (x <= m) {
		update(node << 1, l, m, x);
	} else {
		update(node << 1 | 1, m + 1, r, x);
	}
	t[node] = t[node << 1] + t[node << 1 | 1];
}

int query (int node, int l, int r, int k) {
	if (t[node] < k) {
		return -1;
	}
	if (l == r) {
		return l;
	}
	int m = l + r >> 1;
	if (t[node << 1] >= k) {
		query(node << 1, l, m, k);
	} else {
		query(node << 1 | 1, m + 1, r, k - t[node << 1]);
	}
}

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", arr + i);
		arr[i] = (bool) (arr[i] & 1);
	}
	build(1, 1, n);
	while (q--) {
		int op, x;
		scanf("%d %d", &op, &x);
		if (op == 1) {
			update(1, 1, n, x);
		} else {
			printf("%d\n", query(1, 1, n, x));
		}
	}
	return 0;
}