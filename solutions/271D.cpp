// http://codeforces.com/problemset/problem/271/D

#include <bits/stdc++.h>

using namespace std;

const int N = 1522;
const int LN = 30;
const int SZ = 4e6;

char str[N];
char letters[LN];
int n;
int k;
int pos = 1;
int trie[SZ][LN];
int cnt[SZ];
bool what[LN];
queue < int > q;

inline int insert (int node, int place) {
	int idx = str[place] - 'a';
	if (!trie[node][idx]) {
		trie[node][idx] = ++pos;
	}
	return trie[node][idx];
}

inline int bfs () {
	q.push(1);
	cnt[1] = 0;
	int ret = 0;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		ret += node > 1;
		for (int i = 0; i < 26; ++i) {
			if (trie[node][i] && what[i] + cnt[node] <= k) {
				q.push(trie[node][i]);
				cnt[trie[node][i]] = cnt[node] + what[i];
			}
		}
	}
	return ret;
}

int main() {
	scanf("%s", str);
	n = strlen(str);
	scanf("%s", letters);
	for (int i = 0; i < 26; ++i) {
		what[i] = (letters[i] - '0') ^ 1;
	}
	scanf("%d", &k);
	for (int i = 0; i < n; ++i) {
		int node = insert(1, i);
		for (int j = i + 1; j < n; ++j) {
			node = insert(node, j);
		}
	}
	printf("%d\n", bfs());
	return 0;
}