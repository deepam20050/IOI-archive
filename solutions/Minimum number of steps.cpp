// http://codeforces.com/contest/805/problem/D
// AC

#include <bits/stdc++.h>

using namespace std;

const int md = (int)1e9 + 7;

int main() {
	string s;
	cin >> s;
	long cnt = 0;
	long ans = 0;
	for (int i = s.size() - 1; i >= 0; --i) {
		if (s[i] == 'b') {
			++cnt;
		} else {
			ans += cnt;
			cnt *= 2;
			ans %= md;
			cnt %= md;
		}
	}
	printf("%ld", ans);
	return 0;
}