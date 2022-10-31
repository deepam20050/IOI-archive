// http://www.spoj.com/problems/PATULJCI/

#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const int M = 1e5 + 5;

int arr[N];
vector < int > v[M];
int n;
int c;

struct data {
	int l;
	int r;
	int ans;
	data () {
		l = -1;
		r = -1;
		ans = -1;
	}
} t[N * 5];

int occ (int x, int l, int r) {
	return lower_bound(v[x].begin(), v[x].end(), r + 1) - lower_bound(v[x].begin(), v[x].end(), l);
}

data operator + (const data &a, const data &b) {
	if (a.l == -1) {
		return b;
	}
	if (b.l == -1) {
		return a;
	}
	data res;
	res.l = a.l;
	res.r = b.r;
	int sz = res.r - res.l + 1;
	for (int x : {a.ans, b.ans}) {
		if (occ(x, res.l, res.r) * 2 > sz) {
			res.ans = x;
		}
	}
	return res;
}

void build (int node, int l, int r) {
	if (l == r) {
		t[node].ans = arr[l];
		t[node].l = l;
		t[node].r = l;
		return;
	}
	int m = l + r >> 1;
	build(node << 1, l, m);
	build(node << 1 | 1, m + 1, r);
	t[node] = t[node << 1] + t[node << 1 | 1];
}

data query (int node, int l, int r, int x, int y) {
	if (x > r || y < l) {
		return data();
	}
	if (x <= l && r <= y) {
		return t[node];
	}
	int m = l + r >> 1;
	return query(node << 1, l, m, x, y) + query(node << 1 | 1, m + 1, r, x, y);
}

int main() {
	scanf("%d %d", &n, &c);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", arr + i);
		v[arr[i]].emplace_back(i);
	}
	build (1, 1, n);
	int q;
	scanf("%d", &q);
	while (q--) {
		int l, r;
		scanf("%d %d", &l, &r);
		data ret = query(1, 1, n, l, r);
		if (ret.ans != -1) {
			printf("yes %d\n", ret.ans);
		} else {
			puts("no");
		}
	}
	return 0;
}