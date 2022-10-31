// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/road-to-dmg-8883b64f/description/
// Very nice problem

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int M = 4e5 + 5;
const int LN = 15;
const int MOD = 1e9 + 7;

int C[LN][LN];
int t[M][LN];
int lazy[M];
int arr[N];
int S[LN];

int tc;
int n;
int q;

inline void mod (int &x) {
	if (x >= MOD) {
		x -= MOD;
	}
}

void pre () {
	for (int i = 0; i <= 10; ++i) {
		C[i][0] = 1;
	}
	for (int i = 1; i <= 10; ++i) {
		for (int j = 1; j <= i; ++j) {
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			mod(C[i][j]);
		}
	}
}

inline void join (int node) {
	for (int i = 0; i <= 10; ++i) {
		t[node][i] = t[node << 1][i] + t[node << 1 | 1][i];
		mod(t[node][i]);
	}
}

inline void add (int node, int k) {
	for (int i = 0; i <= 10; ++i) {
		S[i] = t[node][i];
	}
	for (int i = 0; i <= 10; ++i) {
		int val = S[i];
		int b = 1;
		for (int j = 1; j <= i; ++j) {
			b = 1LL * b * k % MOD;
			val += 1LL * S[i - j] * b % MOD * C[i][j] % MOD;
			mod(val);
		}
		t[node][i] = val;
	}
}

inline void push (int node, int l, int r) {
	if (!lazy[node]) {
		return;
	}
	add(node, lazy[node]);
	if (l != r) {
		lazy[node << 1] += lazy[node];
		lazy[node << 1 | 1] += lazy[node];
		mod(lazy[node << 1]);
		mod(lazy[node << 1 | 1]);
	}
	lazy[node] = 0;
}

void build (int node, int l, int r) {
	if (l == r) {
		t[node][0] = 1;
		for (int i = 1; i <= 10; ++i) {
			t[node][i] = 1LL * arr[l] * t[node][i - 1] % MOD;
		}
		return;
	}
	int m = l + r >> 1;
	build(node << 1, l, m);
	build(node << 1 | 1, m + 1, r);
	join(node);
}

void update (int node, int l, int r, int x, int y, int k) {
	push(node, l, r);	
	if (x <= l && r <= y) {
		lazy[node] += k;
		push(node, l, r);
		return;
	}
	int m = l + r >> 1;
	if (x <= m) {
		update(node << 1, l, m, x, y, k);
	}
	if (y > m) {
		update(node << 1 | 1, m + 1, r, x, y, k);
	}
	push(node << 1, l, m);
	push(node << 1 | 1, m + 1, r);
	join(node);
}

int query (int node, int l, int r, int x, int y, int p) {
	push(node, l, r);
	if (x <= l && r <= y) {
		return t[node][p];
	}
	int m = l + r >> 1;
	int ret = 0;
	if (x <= m) {
		ret += query(node << 1, l, m, x, y, p);
	}
	if (y > m ){
		ret += query(node << 1 | 1, m + 1, r, x, y, p);
	}
	mod(ret);
	return ret;
}

int main() {
	pre();
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		memset(lazy, 0, sizeof lazy);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", arr + i);
		}
		build(1, 1, n);
		scanf("%d", &q);
		while (q--) {
			int op;
			scanf("%d", &op);
			if (op == 1) {
				int x, k;
				scanf("%d %d", &x, &k);
				update(1, 1, n, x, x, k);
			} else if (op == 2) {
				int l, r, k;
				scanf("%d %d %d", &l, &r, &k);
				update(1, 1, n, l, r, k);
			} else {
				int l, r, p;
				scanf("%d %d %d", &l, &r, &p);
				printf("%d\n", query(1, 1, n, l, r, p));
			}
		}
	}
	return 0;
}