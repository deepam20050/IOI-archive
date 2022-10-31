// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/shivam-and-expensive-birthday-gift-da58b2f0/editorial/

#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

long long arr[N];
int bit[N];

int n;
int q;

inline void update (int idx, int add) {
	int st = idx;
	while (idx <= n) {
		bit[idx] += add;
		idx += idx & -idx;
	}
}

inline int query (int idx) {
	int ret = 0;
	while (idx) {
		ret += bit[idx];
		idx -= idx & -idx;
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
			update(x, __builtin_popcountll(arr[x] << 1LL | 1LL) - __builtin_popcountll(arr[x]));
			arr[x] = arr[x] << 1LL | 1LL;
		} else if (op == 2) {
			int x;
			scanf("%d", &x);
			update(x, __builtin_popcountll(arr[x] >> 1LL) - __builtin_popcountll(arr[x]));
			arr[x] >>= 1LL;
		} else {
			int x, y;
			scanf("%d %d", &x, &y);
			printf("%d\n", query(y) - query(x - 1));
		}
	}
	return 0;
}