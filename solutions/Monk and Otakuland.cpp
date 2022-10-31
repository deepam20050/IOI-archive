// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/monk-and-otakuland-1/description/

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int M = 1e6;

int lzy[M];
int cnt[M][2];
char str[N];

int n;
int q;

inline void push (int node, int l, int r) {
	if (!lzy[node]) {
		return;
	}
	if (l != r) {
		int lft = node << 1;
		int rgt = lft | 1;
		lzy[lft] ^= 1;
		lzy[rgt] ^= 1;
		swap(cnt[lft][0], cnt[lft][1]);
		swap(cnt[rgt][0], cnt[rgt][1]);
	}
	lzy[node] = 0;
}

inline void join (int node) {
	int lft = node << 1;
	int rgt = lft | 1;
	cnt[node][0] = cnt[lft][0] + cnt[rgt][0];
	cnt[node][1] = cnt[lft][1] + cnt[rgt][1];
}

void build (int node, int l, int r) {
	if (l == r) {
		cnt[node][0] = str[l] == '>';
		cnt[node][1] = str[l] == '<';
		return;
	}
	int m = l + r >> 1;
	build(node << 1, l, m);
	build(node << 1 | 1, m + 1, r);
	join(node);
}

void update (int node, int l, int r, int x, int y) {
	push(node, l, r);
	if (x <= l && r <= y) {
		swap(cnt[node][0], cnt[node][1]);
		lzy[node] ^= 1;
		return;
	}
	int m = l + r >> 1;
	if (x <= m) {
		update(node << 1, l, m, x, y);
	} 
	if (y > m) {
		update(node << 1 | 1, m + 1, r, x, y);
	}
	push(node << 1, l, m);
	push(node << 1 | 1, m + 1, r);
	join(node);
}

int query (int node, int l, int r, int x, int y, bool who) {
	if (l > y || x > r) {
		return 0;
	}
	push(node, l, r);
	if (x <= l && r <= y) {
		return cnt[node][who];
	}
	int m = l + r >> 1;
	return query(node << 1, l, m, x, y, who) + query(node << 1 | 1, m + 1, r, x, y, who);
}

int main() {
	scanf("%d %d %s", &n, &q, str + 1);
	build(1, 1, n - 1);
	while (q--) {
		int op, l, r;
		scanf("%d %d %d", &op, &l, &r);
		if (op == 1) {
			update(1, 1, n - 1, l, r - 1);
		} else {
			bool who = l < r;
			if (l > r) {
				swap(l, r);
			}
			printf("%d\n", query(1, 1, n - 1, l, r - 1, who));
		}
	}
	return 0;
}