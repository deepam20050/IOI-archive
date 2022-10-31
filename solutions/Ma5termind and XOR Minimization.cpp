#include <bits/stdc++.h>

using namespace std;

const int N = 120;
const int MOD = 1e9 + 7;
const int SZ = 5e5;
const int MAX = 1e5;

int trie[SZ][2];
int value[SZ];
bool s[MAX + 5];
int sets[MAX + 5];
int arr[N];
int n;
int pos = 1;

void mod (int &x) {
	if (x >= MOD) {
		x -= MOD;
	}
}

void insert (int x) {
	int node = 1;
	for (int i = 20; i >= 0; --i) {
		bool set = x & (1 << i);
		if (!trie[node][set]) {
			trie[node][set] = pos++;
		}
		node = trie[node][set];
	}
	value[node] = x;
}

int query (int x) {
	int node = 1;
	for (int i = 20; i >= 0; --i) {
		bool set = x & (1 << i);
		if (trie[node][set]) {
			node = trie[node][set];
		} else if (trie[node][set ^ 1]) {\
			node = trie[node][set ^ 1];
		} 
	}
	return value[node];
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
	}
	s[0] = 1;
	sets[0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = MAX; j >= 0; --j) {
			if (s[j]) {
				s[j + arr[i]] = 1;
				sets[j + arr[i]] += sets[j];
				mod(sets[j + arr[i]]);
			}
		}
	}
	for (int i = 1; i <= MAX; ++i) {
		if (s[i]) {
			insert(i);
		}
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int x;
		scanf("%d", &x);
		int res = query(x);
		printf("%d %d\n", res, sets[res]);
	}
	return 0;
}