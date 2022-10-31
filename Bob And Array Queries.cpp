// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/shivam-and-expensive-birthday-gift-da58b2f0/editorial/

#include <bits/stdc++.h>

using namespace std;

const int N= 5e5 + 5;

long long arr[N];
long long t[N << 2];

int n;
int q;

void update (int node, int l, int r, int x, int op) {
	if (l == r) {
		if (op == 1) {
			arr[x] = arr[x] << 1LL | 1LL;
		} else {
			arr[x] >>= 1LL;
		}
		t[node] = __builtin_popcountll(arr[x]);
		return;
	}
	int m = l + r >> 1;
	if (x <= m) {
		update(node << 1, l, m, x, op);
	} else {
		update(node << 1 | 1, m + 1, r, x, op);
	}
	t[node] = t[node << 1] + t[node << 1 | 1];
}

long long query (int node, int l, int r, int x, int y) {
	if (x <= l && r <= y) {
		return t[node];
	}
	int m = l + r >> 1;
	long long ret = 0;
	if (x <= m) {
		ret += query(node << 1, l, m, x, y);
	}
	if (y > m) {
		ret += query(node << 1 | 1, m + 1, r, x, y);
	}
	return ret;
}

int main() {
	scanf("%d %d", &n, &q);
	while (q--) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int x;
			scanf("%d", &x);
			update(1, 1, n, x, 1);
		} else if (op == 2) {
			int x;
			scanf("%d", &x);
			update(1, 1, n, x, 2);
		} else {
			int x, y;
			scanf("%d %d", &x, &y);
			printf("%lld\n", query(1, 1, n, x, y));
		}
	}
	return 0;
}