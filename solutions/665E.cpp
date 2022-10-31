#include <bits/stdc++.h>

using namespace std;

const int SZ = 4e6;
const int LN = 31;

int trie[SZ][2];
int cnt[SZ];
unordered_map < int , int > mp;
int n;
int k;
int pos = 1;

inline void insert (int x) {
	int node = 1;
	for (int i = LN; i >= 0; --i) {
		bool b = x & (1 << i);
		if (!trie[node][b]) {
			trie[node][b] = ++pos;
		}
		node = trie[node][b];
		++cnt[node];
	}
	++mp[x];
}

long long query (int x) {
	int node = 1;
	long long ans = 0;
	for (int i = LN; i >= 0; --i) {
		bool b = x & (1 << i);
		if (b) {
			ans += cnt[trie[node][0]] * 1LL;
		}
		node = trie[node][b];
	}
	return ans + mp[x];
}

int main() {
	scanf("%d %d", &n, &k);
	long long ans = 0;
	int curr = 0;
	insert(0);
	for (int i = 1, x; i <= n; ++i) {
		scanf("%d", &x);
		curr ^= x;
		ans += query(curr ^ k);
		insert(curr);
	}
	printf("%lld\n", ans);
	return 0;
}