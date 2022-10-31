// https://www.codechef.com/problems/RBTREE

#include <bits/stdc++.h>

using namespace std;

int shift;

int log (int x) {
	int ans = 0;
	while (x != 1) {
		++ans;
		x >>= 1;
	}
	return ans + shift;
}

int main() {
	int q;
	scanf("%d", &q);
	while (q--) {
		char t[3];
		scanf("%s", t);
		int x, y;
		if (t[1] == 'b') {
			scanf("%d %d", &x, &y);
			int ans = 0;
			while (x != y) {
				if (x > y) {
					ans += !(log(x) % 2);
					x >>= 1;
				} else {
					ans += !(log(y) % 2);
					y >>= 1;
				}
			}
			ans += !(log(x) % 2);
			printf("%d\n", ans);
		} else if (t[1] == 'r') {
			scanf("%d %d", &x, &y);
			int ans = 0;
			while (x != y) {
				if (x > y) {
					ans += (log(x) % 2);
					x >>= 1;
				} else {
					ans += (log(y) % 2);
					y >>= 1;
				}
			}
			ans += (log(x) % 2);
			printf("%d\n", ans);
		} else {
			++shift;
		}
	}
	return 0;
}