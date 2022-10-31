// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/fibonacci-with-gcd-16/description/

#include <bits/stdc++.h>

using namespace std;
using v = vector < vector < int > >;

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

int t[N << 2];
int arr[N];

int n;
int q;

inline void mod (int &x) {
	if (x >= MOD) {
		x -= MOD;
	}
}

void build (int node, int l, int r){
	if (l == r) {
		t[node] = arr[l];
		return;
	}
	int m = l + r >> 1;
	build(node << 1, l, m);
	build(node << 1 | 1, m + 1, r);
	t[node] = __gcd(t[node << 1], t[node << 1 | 1]);
}

int query (int node, int l, int r, int x, int y) {
	if (x > r || y < l) {
		return 0;
	}
	if (x <= l && r <= y) {
		return t[node];
	}
	int m = l + r >> 1;
	return __gcd(query(node << 1, l, m, x, y), query(node << 1 | 1, m + 1, r, x, y));
}

inline v mult (const v &a, const v &b) {
	v res = {{0, 0}, {0, 0}};
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 2; ++k) {
				res[i][j] += (1LL * a[i][k] * b[k][j]) % MOD;
				mod(res[i][j]);
			}
		}
	}
	return res;
}

v matrix_expo (int y) {
	v res = {{1, 0}, {0, 1}};
	v x = {{0, 1}, {1, 1}};
	while (y > 0) {
		if (y & 1) {
			res = mult(res, x);
		}	
		y >>= 1;
		x = mult(x, x);
	}
	return res;
}

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", arr + i);
	}
	build(1, 1, n);
	while (q--) {
		int l, r;
		scanf("%d %d", &l, &r);
		int gcd = query(1, 1, n, l, r);
		v ret = matrix_expo(gcd);
		printf("%d\n", ret[0][1]);
	}
	return 0;
}