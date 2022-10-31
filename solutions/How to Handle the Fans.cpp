// http://www.spoj.com/problems/AKVQLD03/
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 1;

long bit[N];

int n, q;

void update(int idx,int val) {
	while (idx <= n) {
		bit[idx] += val;
		idx += idx & (-idx);
	}
}

long query(int idx) {
	long ans = 0;
	while (idx > 0) {
		ans += bit[idx];
		idx -= idx & (-idx);
	}
	return ans;
}

int main() {
	scanf("%d %d", &n, &q);
	while (q--) {
		string s; int x, y;
		cin >> s >> x >> y;
		if (s[0] == 'a') {
			update(x, y);
		} else {
			printf("%ld\n", query(y) - query(x - 1));
		}
	}

	return 0;
}