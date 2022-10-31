// https://www.codechef.com/JUNE18B/problems/SHKSTR

#include <bits/stdc++.h>

using namespace std;

const int N = 2e6;

int trie[N][26];
int val[N];
int last[N];

int pos = 1;
int mx;
string s;

inline void insert (int at) {
	int node = 1;
	for (char c : s) {
		int idx = c - 'a';
		if (!trie[node][idx]) {
			trie[node][idx] = ++pos;
			val[trie[node][idx]] = at;
		}
		node = trie[node][idx];
	}
	if (!last[node]) {
		last[node] = at;
	}
}

inline string query () {
	int node = 1;
	string ret;
	for (char c : s) {
		int idx = c - 'a';
		if (!trie[node][idx] || val[trie[node][idx]] > mx) {
			break;
		}
		ret += c;
		node = trie[node][idx];
	}
	if (last[node] > 0 && last[node] <= mx) {
		return ret;
	}
	for (int j = 0; j < 10; ++j) {
		char add = '.';
		for (int i = 0; i < 26; ++i) {
			if (trie[node][i] && val[trie[node][i]] <= mx) {
				add = i + 'a';
				break;
			}
		}
		if (add == '.') {
			break;
		}
		ret += add;
		if (last[trie[node][add - 'a']] <= mx && last[trie[node][add - 'a']] > 0) {
			break;
		}
		node = trie[node][add - 'a'];
	}
	return ret;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> s;
		insert(i);
	}
	int q;
	cin >> q;
	while (q--) {
		cin >> mx >> s;
		cout << query() << '\n';
	}
	return 0;
}