// https://www.spoj.com/problems/CVJETICI/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int bit[N];
int cnt[N];

inline void update (int idx, int add) {
	while (idx < N) {
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
	int n;
	scanf("%d", &n);
	while (n--) {
		int l, r;
		scanf("%d %d", &l, &r);
		int sum1 = query(l) - cnt[l];
		int sum2 = query(r) - cnt[r];
		printf("%d\n", sum1 + sum2);
		cnt[l] += sum1;
		cnt[r] += sum2;
		update(l + 1, 1);
		update(r, -1);
	}
	return 0;
}