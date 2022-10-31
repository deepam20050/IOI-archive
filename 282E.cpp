// http://codeforces.com/problemset/problem/282/E

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int SZ = 4e6;
const int LN = 63;

long long arr[N];
int trie[SZ][2];
int n;
int pos = 1;

inline void insert (long long x) {
	int node = 1;
	for (int i = LN; i >= 0; --i) {
		bool b = x & (1LL << i);
		if (b) {
			if (!trie[node][b]) {
				trie[node][b] = ++pos;
			}
			node = trie[node][b];
		} else {
			if (!trie[node][b]) {
				trie[node][b] = ++pos;
			}
			node = trie[node][b];
		}
	}
}

inline long long query (long long x) {
	long long ans = 0;
	int node = 1;
	for (int i = LN; i >= 0; --i) {
		bool b = x & (1LL << i);
		if (trie[node][b ^ 1]) {
			ans |= 1LL << i;
			node = trie[node][b ^ 1];
		} else {
			node = trie[node][b];
		}
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", arr + i);
	}
	long long pref = 0;
	for (int i = 1; i <= n; ++i) {
		pref ^= arr[i];
	}
	long long ans = pref;
	insert(0);
	long long suff = 0;
	for (int i = n; i >= 0; --i) {
		pref ^= arr[i + 1];
		ans = max(ans, query(pref));
		suff ^= arr[i];
		insert(suff);
	}
	printf("%lld\n", ans);
	return 0;
}