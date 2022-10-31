// AC
// Very good problem, one of the best I've ever solved

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int bit[N];
int arr[N];
pair < int, int > temp[N];
int at_arr[N];
int at_bit[N];
int n;
int q;

inline void update (int idx, int add) {
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

int upper_bound (int x) {
	int l = 1;
	int r = n + 1;
	while (l < r) {
		int m = l + r >> 1;
		if (query(m) > x) {
			r = m;
		} else {
			l = m + 1;
		}
	}
	return l;
}

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		temp[i] = {x, i};
	}
	sort(temp + 1, temp + n + 1);
	for (int i = 1; i <= n; ++i) {
		int val = temp[i].first;
		int pos = temp[i].second;
		arr[i] = val;
		at_arr[i] = pos;
		at_bit[pos] = i;
	}
	// create difference array
	for (int i = 1; i <= n; ++i) {
		update(i, arr[i] - arr[i - 1]);
	}
	while (q--) {
		int op, x;
		scanf("%d %d", &op, &x);
		if (op == 1) {
			++x;
			int ind = at_bit[x];
			int val = query(ind);
			int largest_pos = upper_bound(val) - 1;
			int pos_in_arr = at_arr[largest_pos];
			update(largest_pos, 1);
			update(largest_pos + 1, -1);
			swap(at_bit[x], at_bit[pos_in_arr]);
			at_arr[ind] = pos_in_arr;
			at_arr[largest_pos] = x;
		} else if (op == 2) {
			printf("%d\n", n - upper_bound(x - 1) + 1);
		} else {
			int idx = upper_bound(x - 1);
			update(idx, -1);
		}
	}
	return 0;
}