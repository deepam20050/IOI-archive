// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/modified-lis-1/description/

#include <bits/stdc++.h>

using namespace std;
using pi = pair < int, int >;

const int N = 1e5 + 1;
const int MOD = 1e9 + 7;

int n;

inline void mod (int &x) {
	if (x >= MOD) {
		x -= MOD;
	}
}

inline pi join (const pi &a, const pi &b) {
	pi ret;
	ret = max(a, b);
	if (a.first == b.first) {
		ret.second = a.second + b.second;
	}
	mod(ret.second);
	return ret;
}

struct segtree {
	pi t[N << 2];
	void update (int node, int l, int r, int x, pi &what) {
		if (l == r) {
			++what.first;
			if (what.second == 0) {
				what.second = 1;
			}
			t[node] = join(t[node], what);
			return;
		}
		int m = l + r >> 1;
		if (x <= m) {
			update(node << 1, l, m, x, what);
		} else {
			update(node << 1 | 1, m + 1, r, x, what);
		}
		t[node] = join(t[node << 1], t[node << 1 | 1]);
	}
	pi query (int node, int l, int r, int x, int y) {
		if (x > y) {
			return {0, 0};
		}
		if (x <= l && r <= y) {
			return t[node];
		}
		int m = l + r >> 1;
		pi a = {0, 0}, b = {0, 0};
		if (x <= m) {
			a = query(node << 1, l, m, x, y);
		}
		if (y > m) {
			b = query(node << 1 | 1, m + 1, r, x, y);
		}
		return join(a, b);
	}
};

segtree pos;
segtree neg;

int main() {
	scanf("%d", &n);
	while (n--) {
		int x;
		scanf("%d", &x);
		if (x > 0) {
			pi best = neg.query(1, 1, N - 1, 1, x - 1);
			pos.update(1, 1, N - 1, x, best); 
		} else {
			pi best = pos.query(1, 1, N - 1, 1, -x - 1);
			neg.update(1, 1, N - 1, -x, best);
		}
	}
	pi ret = join(pos.t[1], neg.t[1]);
	printf("%d %d\n", ret.first, ret.second);
	return 0;
}