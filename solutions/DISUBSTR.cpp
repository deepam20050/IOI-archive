// http://www.spoj.com/problems/DISUBSTR/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const int SZ = 1e6;

int trie[SZ][56];
unordered_map < char, int > kahan;
string s;
int pos;
int ans;

inline int insert (int idx, int node) {
	if (!trie[node][idx]) {
		trie[node][idx] = ++pos;
		++ans;
	}
	return trie[node][idx];
}

int main() {
	int idxx = 0;
	for (char ch = 'a'; ch <= 'z'; ++ch) {
		kahan[ch] = idxx++;
	}
	for (char ch = 'A'; ch <= 'Z'; ++ch) {
		kahan[ch] = idxx++;
	}
	ios_base::sync_with_stdio(0);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> s;
		memset(trie, 0, sizeof trie);
		pos = 1;
		ans = 0;
		int n = s.size();
		for (int i = 0; i < n; ++i) {
			int node = 1;
			for (int j = i; j < n; ++j) {
				node = insert(kahan[s[j]], node);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}