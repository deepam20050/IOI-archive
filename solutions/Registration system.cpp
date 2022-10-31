// http://codeforces.com/problemset/problem/4/C
// AC

#include <bits/stdc++.h>

using namespace std;

unordered_map <string, int> mp;

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		string s;
		cin >> s;
		++mp[s];
		if (mp[s] == 1) {
			puts("OK");
			continue;
		} else {
			s += to_string(mp[s] - 1);
			cout << s << '\n';
			continue;
		}
	}
	return 0;
}