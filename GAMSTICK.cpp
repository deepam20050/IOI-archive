#include "bits/stdc++.h"

using namespace std;

long long abso (long long x) {
	return x < 0 ? -x : x;
}

const string ans1 = "Miron", ans2 = "Slava", ans3 = "Draw";

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		long long n, y1, y2;
		int x1, x2;
		scanf("%lld %d %lld %d %lld", &n, &x1, &y1, &x2, &y2);
		bool change = 0;
		if (y1 > y2) {
			swap(x1, x2);
			swap(y1, y2);
			change = 1;
		}
		string ans;
		if (x1 == x2) {
			long long mid = (y1 + y2) >> 1;
			if (2 * mid < 2 * (n - mid)) {
				ans = ans1;
			} else {
				ans = ans2;
			}
		} else {
			if (y1 == y2) {
				ans = ans3;
			} else if (abso(y2 - y1)) {
				if (2 * y1 > 2 * (n - y1)) {
					ans = ans1;
				} else {
					ans = ans3;
				}
			} else {
				if (2 * y1 > 2 * (n - y1)) {
					ans = ans1;
				} else if (2 * y1 < 2 * (n - y1)) {
					ans = ans2;
				} else {
					ans = ans3;
				}
			}
		}
		if (change) {
			if (ans == ans1) {
				ans = ans2;
			} else if (ans == ans2) {
				ans = ans1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}