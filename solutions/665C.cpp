// http://codeforces.com/problemset/problem/665/C
// AC

#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
	cin >> s;
	int n = s.size();

	for (int i = 0, j = 0; i < n; i = j) {
		while (j < n && s[i] == s[j]) ++j;
		char c = 'a';
		while (c == s[i] || (i > 0 && s[i-1] == c) || (j < n && s[j] == c))
			++c;
		for (int k = i; k < j; ++k) {
			if ((i+k)&1)
				s[k] = c;
		}
	}

	cout << s << '\n';

	return 0;
}