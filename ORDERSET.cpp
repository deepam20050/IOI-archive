// https://www.spoj.com/problems/ORDERSET/

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int t[N << 2];
char str[N][4];
int val[N];
int tmp[N];

void update (int node, int l, int r, int x, int add) {
	if (l == r) {
		t[node] = add;
		return;
	}
	int m = l + r >> 1;
	if (x <= m) {
		update(node << 1, l, m, x, add);
	} else {
		update(node << 1 | 1, m + 1, r, x, add);
	}
	t[node] = t[node << 1] + t[node << 1 | 1];
}

int kth (int node, int l, int r, int k) {
	if (t[node] < k) {
		return -1;
	}
	if (l == r) {
		return l;
	}
	int m = l + r >> 1;
	if (t[node << 1] >= k) {
		return kth(node << 1, l, m, k);
	}
	return kth(node << 1 | 1, m + 1, r, k - t[node << 1]);
}

int query (int node, int l, int r, int x, int y) {
	if (x <= l && r <= y) {
		return t[node];
	}
	int m = l + r >> 1;
	int ret = 0;
	if (x <= m) {
		ret += query(node << 1, l, m, x, y);
	}
	if (y > m) {
		ret += query(node << 1 | 1, m + 1, r, x, y);
	}
	return ret;
}

int main() {
	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; ++i) {
		scanf("%s %d", str[i], val + i);
		tmp[i] = val[i];
	}
	tmp[0] = -2e9;
	sort(tmp, tmp + q + 1);
	for (int i = 1; i <= q; ++i) {
		char op = str[i][0];
		int x = val[i];
		if (op == 'I') {
			int at = lower_bound(tmp, tmp + q + 1, x) - tmp;
			update(1, 1, q, at, 1);
		} else if (op == 'D') {
			int at = lower_bound(tmp, tmp + q + 1, x) - tmp;
			update(1, 1, q, at, 0);
		} else if (op == 'K') {
			int ans = kth(1, 1, q, x);
			ans == -1 ? puts("invalid") : printf("%d\n", tmp[ans]);
		} else {
			int at = lower_bound(tmp, tmp + q + 1, x) - tmp;
			if (at <= 1) {
				puts("0");
				continue;
			}
			printf("%d\n", query(1, 1, q, 1, at - 1));
		}
	}
	return 0;
}