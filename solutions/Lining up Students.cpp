// http://lightoj.com/volume_showproblem.php?problem=1187

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct data {
	int val;
	int sum;

	data () {
		val = 0;
		sum = 0;
	}
} t[N << 2];

int arr[N];
int tc;
int n;

void build (int node, int l, int r) {
	if (l == r) {
		t[node].sum = 1;
		t[node].val = n - l + 1;
		return;
	}
	int m = l + r >> 1;
	build(node << 1, l, m);
	build(node << 1 | 1, m + 1, r);
	t[node].sum = t[node << 1].sum + t[node << 1 | 1].sum;
}

int query (int node, int l, int r, int x) {
	if (l == r) {
		return t[node].val;
	}
	int m = l + r >> 1;
	int ret;
	if (x <= t[node << 1].sum) {
		ret = query(node << 1, l, m, x);
	} else {
		ret = query(node << 1 | 1, m + 1, r, x - t[node << 1].sum);
	}
	return ret;
}

void update (int node, int l, int r, int x) {
	if (l == r) {
		t[node].sum = 0;
		return;
	}
	int m = l + r >> 1;
	if (x <= m) {
		update(node << 1, l, m, x);
	} else {
		update(node << 1 | 1, m + 1, r, x);
	}
	t[node].sum = t[node << 1].sum + t[node << 1 | 1].sum;
}

int main() {
	scanf("%d", &tc);
	for (int tt = 1; tt <= tc; ++tt) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", arr + i);
		}
		build(1, 1, n);
		for (int i = n; i >= 1; --i) {
			int val = query(1, 1, n, arr[i] + 1);
			if (i == 1) {
				printf("Case %d: %d\n", tt, val);
			}
			update(1, 1, n, n - val + 1);
		}
	}
	return 0;
}