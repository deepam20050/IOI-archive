// https://www.spoj.com/problems/KQUERYO/
// Beauty with segtree + vectors

#include <bits/stdc++.h>

using namespace std;

const int N = 3e4 + 5;

int arr[N];
vector < int > t[N << 2];
int n;
int q;

inline void join (vector < int > &res, vector < int > &l, vector < int > &r) {
	res.resize(l.size() + r.size());
	int i = 0;
	int j = 0;
	int n = l.size();
	int m = r.size();
	int k = 0;
	while (i < n && j < m) {
		if (l[i] <= r[j]) {
			res[k] = l[i];
			++i;
		} else {
			res[k] = r[j];
			++j;
		}
		++k;
	}
	while (i < n) {
		res[k++] = l[i++];
	}
	while (j < m) {
		res[k++] = r[j++];
	}
}

void build (int node, int l, int r) {
	if (l == r) {
		t[node].emplace_back(arr[l]);
		return;
	}
	int m = l + r >> 1;
	build(node << 1, l, m);
	build(node << 1 | 1, m + 1, r);
	join(t[node], t[node << 1], t[node << 1 | 1]);
}

int query (int node, int l, int r, int x, int y, int val) {
	if (x <= l && r <= y) {
		return t[node].size() - (upper_bound(t[node].begin(), t[node].end(), val) - t[node].begin());
	}
	int m = l + r >> 1;
	int ret = 0;
	if (x <= m) {
		ret += query(node << 1, l, m, x, y, val);
	}
	if (y > m) {
		ret += query(node << 1 | 1, m + 1, r, x, y, val);
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", arr + i);
	}
	build(1, 1, n);
	scanf("%d", &q);
	int ans = 0;
	while (q--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		int i = a ^ ans;
		int j = b ^ ans;
		int k = c ^ ans;
		if (i < 1) {
			i = 1;
		}
		if (j > n) {
			j = n;
		}
		if (i > j) {
			ans = 0;
			puts("0");
			continue;
		}
		ans = query(1, 1, n, i, j, k);
		printf("%d\n", ans);
	}
	return 0;
}