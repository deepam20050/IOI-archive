// http://codeforces.com/contest/832/problem/B
// Good problem on implementation

#include <bits/stdc++.h>

using namespace std;

bool good[27];

bool match (string pat, string s) {
	if (pat.size() != s.size()) {
		return 0;
	}
	for (int i = 0; i < pat.size(); ++i) {
		if (pat[i] == '?' && !good[s[i] - 'a']) {
			return 0;
		} else if (pat[i] != '?' && pat[i] != s[i]) {
			return 0;
		}
	}
	return 1;
}

int main() {
	string goods, pat;
	int n;
	cin >> goods >> pat >> n;
	for (const auto &e: goods) {
		good[e - 'a'] = 1;
	}
	auto p = pat.find('*');
	while (n--) {
		string s;
		cin >> s;
		if (s.size() < pat.size() - 1) {
			puts("NO");
		} else if (p == string::npos) {
			cout << (match(pat, s) ? "YES" : "NO") << '\n';
		} else {
			bool ok = 1;
			ok &= match(pat.substr(0, p), s.substr(0, p));
			reverse(pat.begin(), pat.end());
			reverse(s.begin(), s.end());
			p = pat.size() - p - 1;
			ok &= match(pat.substr(0, p), s.substr(0, p));
			reverse(pat.begin(), pat.end());
			reverse(s.begin(), s.end());
			p = pat.size() - p - 1;
			for (int i = p; i < s.size() - (pat.size() - p - 1); ++i) {
				ok &= !good[s[i] - 'a'];
			}
			ok ? puts("YES") : puts("NO");
		}
	}
	return 0;
}