// http://codeforces.com/gym/101350/problem/H
// AC

#include <bits/stdc++.h>

using namespace std;

const string mirror = "AHIMOTUVWXY";

string s;

int main() {
	int t;
	scanf("%d",&t);
	getchar();
	while (t--) {
		cin >> s;

		int n = s.size();
		bool flag = 1;
		for (int i = 0, j = n - 1; i < n && j >= 0; ++i, --j) {
			if (s[i] != s[j]) {
				flag = 0;
				break;
			}
		}

		if (!flag) {
			puts("no");
			continue;
		}
		for (const auto &e: s) {
			if (!binary_search(mirror.begin(), mirror.end(), e)) {
				flag = 0;
				break;
			}
		}
		flag ? puts("yes") : puts("no");
	}

	return 0;
}