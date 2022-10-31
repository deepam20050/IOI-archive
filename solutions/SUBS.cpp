// http://www.spoj.com/problems/SUBS/

#include <bits/stdc++.h>

using namespace std;

string x, y;

bool F(int rep) {
	if (x.size() * rep > y.size()) {
		return 0;
	}
	string s;
	for (char c: x) {
		int temp = rep;
		while (temp--) {
			s += c;
		}
	}
	int i = 0, j = 0;
	int n = y.size(), m = s.size();
	while (i < n && j < m) {
		if (y[i] == s[j]) {
			++j;
		}
		++i;
	}
	return j == m;
}

int main() {
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> x >> y;
		int l = 0, r = y.size(), ans = 0;
		for (int i = 0; i < 20; ++i) {
			int mid = (l + r) >> 1;
			if (F(mid)) {
				l = mid + 1;
				ans = mid;
			} else {
				r = mid - 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}