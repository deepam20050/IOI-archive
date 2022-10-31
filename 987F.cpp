#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 22;
const int LN = 23;
const int SZ = 7e6;

int trie[SZ][2];
int p[N];
int sz[N];
queue < pair < int, pair < int, int > > > q;
bool used1[N];
bool used2[N];
bool yes[N];

int n;
int m;
int pos = 1;

inline int find_set (int x) {
	return p[x] == x ? x : p[x] = find_set(p[x]);
}

inline void join (int x, int y) {
	x = find_set(x);
	y = find_set(y);
	if (x == y) {
		return;
	}
	if (sz[x] < sz[y]) {
		swap(x, y);
	}
	sz[x] += sz[y];
	p[y] = x;
}

inline void insert (int x) {
	int node = 1;
	for (int i = LN - 1; i >= 0; --i) {
		bool set = x & (1 << i);
		if (!trie[node][set]) {
			trie[node][set] = ++pos;
		}
		node = trie[node][set];
	}
}

inline void bfs (int x) {
	q.push({1, {LN - 1, 0}});
	while (!q.empty()) {
		int node = q.front().first;
		int level = q.front().second.first;
		int curr = q.front().second.second;
		q.pop();
		if (level == -1) {
			join(x, curr);
			yes[curr] = 1;
			continue;
		}
		bool set = x & (1 << level);
		if (set) {
			if (trie[node][0]) {
				q.push({trie[node][0], {level - 1, curr}});
			}
			continue;
		}
		if (trie[node][0]) {
			q.push({trie[node][0], {level - 1, curr}});
		}
		if (trie[node][1]) {
			q.push({trie[node][1], {level - 1, curr | (1 << level)}});
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < N; ++i) {
		p[i] = i;
		sz[i] = 1;
	}
	for (int i = 0; i < m; ++i) {
		int x;
		scanf("%d", &x);
		insert(x);
		used1[x] = 1;
	}
	for (int i = 0; i < (1 << n); ++i) {
		if (used1[i] && !yes[i]) {
			bfs(i);
		}
	}
	int ans = 0;
	for (int i = 0; i < (1 << n); ++i) {
		if (used1[i]) {
			int where = find_set(i);
			ans += used2[where] == 0;
			used2[find_set(i)] = 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}