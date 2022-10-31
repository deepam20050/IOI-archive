#include <bits/stdc++.h>

using namespace std;

struct data {
	vector < int > indices;
	int left;
	int right;
	data () {
		left = 0;
		right = 0;
	}
};

struct trie {
	data child[N * LN];
};

void insert (int x, int idx) {
	int node = 1;
	for (int i = LN; i >= 0; --i) {
		bool set = x & (1 << i);
		if (set) {
			if (!child[node].right) {
				child[node].right = ++pos; 
			}
			node = child[node].right;
		} else {
			if (!child[node].left) {
				child[node].left = ++pos;
			}
			node = child[node].right;
		}
		child[node].indices.emplace_back(idx);
	}
}

void erase (int x, int idx) {
	int node = 1;
	for (int i = LN; i >= 0; --i) {
		bool set = x & (1 << i);
		if (set) {
			node = child[node].right;
		} else {
			node = child[node].left;
		}
		child[node].indices.pop_back();
	}
}

int xorquery (int l, int r, int x) {
	
}

int main() {
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int op;
		scanf("%d", &op);
		if (!op) {
			scanf("%d", arr[++curr]);
			insert(arr[curr]);
		} else if (op == 1) {
			int l, r, x;
			scanf("%d %d %d", &l, &r, &x);
			printf("%d\n", xorquery(l, r, x));
		} else if (op == 2) {
			int k;
			scanf("%d", &k);
			while (k--) {
				erase(arr[curr--]);
			}
		} else if (op == 3) {
			int l, r, x;
			scanf("%d %d %d", &l, &r, &x);
			printf("%d\n", kquery(l, r, x));
		} else {
			int l, r, k;
			scanf("%d %d %d", &l, &r, &k);
			printf("%d\n", kthmin(l, r, k));
		}
	}
	return 0;
}