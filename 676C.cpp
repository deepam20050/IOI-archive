// http://codeforces.com/problemset/problem/676/C
// AC

#include <bits/stdc++.h>

using namespace std;

int n,k;
string s;
int ans = -1;

void solve(char ch) {
	int l = 0, r = -1, change = 0;

	for (int i = 0; i < n; ++i) {
		++r;
		if (s[i] == ch) ++change;
		while (change > k) {
			char x = s[l];
			if (x == ch) --change;
			++l;
		}
		ans = max(ans,r-l+1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);

	cin >> n >> k;
	cin >> s;

	solve('a');
	solve('b');

	cout << ans << '\n';

	return 0;
}