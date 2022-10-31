// http://codeforces.com/problemset/problem/779/B
// AC

#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	int k;
	cin >> s >> k;
	int ans = 0;
	for (int i = s.size() - 1, zeroes = 0; i >= 0; --i) {
		if (s[i] == '0') {
			++zeroes;
		}
		if (s[i] != '0') {
			++ans;
		}
		if (zeroes == k) {
			return !printf("%d", ans);
		}
	}
	printf("%d", s.size() - 1);
	return 0;
}