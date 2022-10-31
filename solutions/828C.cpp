// http://codeforces.com/contest/828/problem/C

#include <bits/stdc++.h>

using namespace std;

const int N = 100010, M = 2e6;;

vector < pair < pair < int, int>, int > > pi;
string s[N];

char ans[M];

int main() {
	for (int i = 0; i < M; ++i) {
		ans[i] = 'a';
	}
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		int sz = s[i].size();
		int x;
		scanf("%d", &x);
		while (x--) {
			int idx;
			scanf("%d", &idx);
			pi.push_back({{idx - 1, i}, sz});
		}
	}
	sort(pi.begin(), pi.end());
	int sz = 0;
	for (const auto &e: pi) {
		if (e.first.first + e.second > sz) {
			for (int i = max(e.first.first, sz); i < e.first.first + e.second; ++i) {
				ans[i] = s[e.first.second][i - e.first.first];
			}
			sz = e.first.first + e.second;
		}
	}
	for (int i = 0; i < sz; ++i) {
		putchar(ans[i]);
	}
	return 0;
}