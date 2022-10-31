#include <bits/stdc++.h>

using namespace std;

struct segtree {
	int ans;
	int lzy;
	segtree *lft;
	segtree *rgt;
	segtree () {
		ans = 0;
		lzy = 0;
		lft = nullptr;
		rgt = nullptr;
	}
};

inline void push (segtree *node, int l, int r) {
	if (!node->lzy) {
		return;
	}
	node->ans += node->lzy;
	if (l != r) {
		// if (node->lft == nullptr) {
		// 	node->lft = new segtree();
		// }
		// node->lft->lzy += node->lzy;
		// if (node->rgt == nullptr) {
		// 	node->rgt = new segtree();
		// }
		// node->rgt->lzy += node->lzy;
		if (node->lft != nullptr) {
			node->lft->lzy += node->lzy;
		}
		if (node->rgt != nullptr) {
			node->rgt->lzy += node->lzy;
		}
	}
	node->lzy = 0;
}

void update (segtree *node, int l, int r, int x, int y) {
	if (x <= l && r <= y) {
		node->lzy += r - l + 1;
		push(node, l, r);
		return;
	}
	push(node, l, r);
	int m = l + r >> 1;
	if (x <= m) {
		if (node->lft == nullptr) {
			node->lft = new segtree();
		}
		update(node->lft, l, m, x, y);
	}
	if (y > m) {
		if (node->rgt == nullptr) {
			node->rgt = new segtree();
		}
		update(node->rgt, m + 1, r, x, y);
	}
	if (node->lft != nullptr) {
		push(node->lft, l, m);
		node->ans += node->lft->ans;
	}
	if (node->rgt != nullptr) {
		push(node->rgt, m + 1, r);
		node->ans += node->rgt->ans;
	}
}

int query (segtree *node, int l, int r, int x, int y) {
	push(node, l, r);
	if (x <= l && r <= y) {
		return node->ans;
	}
	int m = l + r >> 1;
	int ret = 0;
	if (x <= m && node->lft != nullptr) {
		ret += query(node->lft, l, m, x, y);
	}
	if (y > m && node->rgt != nullptr) {
		ret += query(node->rgt, m + 1, r, x, y);
	}
	return ret;
}

segtree *root = new segtree();

int main() {
	int q;
	scanf("%d", &q);
	int c = 0;
	int n = 1e9;
	while (q--) {
		int d, x, y;
		scanf("%d %d %d", &d, &x, &y);
		x += c;
		y += c;
		if (d == 1) {
			int ans = query(root, 1, n, x, y);
			printf("%d\n", ans);
			c += ans;
		} else {
			update(root, 1, n, x, y);
		}
	}
	return 0;
}