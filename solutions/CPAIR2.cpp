// http://www.spoj.com/problems/CPAIR2/

#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;
const int M = 1e5 + 1;
const int SQN = 225;

int arr[N];
long long bit[M];
long long print[N];
int n;
int q;
int k;
long long ans;

struct query {
	int l;
	int r;
	int id;
	int block;
	query () { }
	query (int _l, int _r ,int _id) {
		l = _l;
		r = _r;
		id = _id;
		block = _l / SQN;
	}
	bool operator < (const query &b) const {
		return b.block == block ? r < b.r : block < b.block;
	}
} Q[N];

inline void update (int idx, long long what) {
	while (idx < M) {
		bit[idx] += what;
		idx += idx & -idx;
	}
}

inline int ask (int idx) {
	if (idx >= M) {
		return 0;
	}
	long long ret = 0;
	while (idx > 0) {
		ret += bit[idx];
		idx -= idx & -idx;
	}
	return ret;
}

inline void add (int idx) {
	ans += ask(arr[idx] - abs(k));
	int tmp = arr[idx] + abs(k) - 1;
	if (tmp < M) {
		ans += ask(M - 1) - ask(tmp);
	}
	update(arr[idx], 1LL);
}

inline void remove (int idx) {
	ans -= ask(arr[idx] - abs(k));
	int tmp = arr[idx] + abs(k) - 1;
	if (tmp < M) {
		ans -= ask(M - 1) - ask(tmp);
	}
	update(arr[idx], -1LL);
}

int main() {
	scanf("%d %d %d", &n, &q, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", arr + i);
	}
	for (int i = 0; i < q; ++i) {
		int l, r;
		scanf("%d %d", &l, &r);
		Q[i] = query(l, r, i);
	}
	sort(Q, Q + q);
	int mo_left = 1;
	int mo_right = 0;
	for (int i = 0; i < q; ++i) {
		int l = Q[i].l;
		int r = Q[i].r;
		while (mo_left < l) {
			remove(mo_left);
			++mo_left;
		}
		while (mo_right < r) {
			++mo_right;
			add(mo_right);
		}
		while (mo_left > l) {
			--mo_left;
			add(mo_left);
		}
		while (mo_right > r) {
			remove(mo_right);
			--mo_right;
		}
		print[Q[i].id] = ans;
	}
	for (int i = 0; i < q; ++i) {
		printf("%lld\n", print[i]);
	}
	return 0;
}