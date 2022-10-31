// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/micros-house-30/

#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e4 + 20;
const int M = 25;
const int SZ = 5e5;
 
struct data {
	int arr[2];
	int change;
};
 
int arr[N][M];
int sum[N][M];
int dwn[N][M];
data trie[SZ];
int n;
int m;
int ans;
int iter;
int pos;
 
inline void clear_trie () {
	++iter;
	pos = 1;
}
 
void insert (int val) {
	int node = 1;
	for (int i = 31; i >= 0; --i) {
		bool set = val & (1 << i);
		if (trie[node].change != iter) {
			trie[node].change = iter;
			trie[node].arr[set] = 0;
			trie[node].arr[set ^ 1] = 0;
		}
		if (trie[node].change == iter && !trie[node].arr[set]) {
			trie[node].arr[set] = ++pos;
		}
		node = trie[node].arr[set];
	}
}
 
int query (int x) {
	int node = 1;
	int val = 0;
	for (int i = 31; i >= 0; --i) {
		bool set = x & (1 << i);
		if (set == 0) {
			if (trie[node].change == iter) {
				if (trie[node].arr[1]) {
					val += 1 << i;
					node = trie[node].arr[1];
				} else {
					node = trie[node].arr[0];
				}
			} else {
				break;
			}
		} else {
			if (trie[node].change == iter) {
				if (trie[node].arr[0]) {
					val += 1 << i;
					node = trie[node].arr[0];
				} else {
					node = trie[node].arr[1];
				}
			} else {
				break;
			}
		}
	}
	return val;
}
 
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%d", arr[i] + j);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			sum[i][j] = sum[i - 1][j] ^ sum[i][j - 1] ^ sum[i - 1][j - 1] ^ arr[i][j];
		}
	}
	for (int i = n; i >= 1; --i) {
		for (int j = 1; j <= m; ++j) {
			dwn[i][j] = dwn[i + 1][j] ^ dwn[i][j - 1] ^ dwn[i + 1][j - 1] ^ arr[i][j];
		}
	}
	ans = sum[n][m];
	for (int i = 1; i <= m - 1; ++i) {
		for (int j = i + 1; j <= m; ++j) {
			int total = sum[n][j] ^ sum[n][i - 1];
			ans = max(ans, total);
			clear_trie();
			for (int k = n; k >= 1; --k) {
				int curr = dwn[k][j] ^ dwn[k][i - 1];
				ans = max(ans, curr);
				insert(curr);
			}
			for (int k = 1; k <= n; ++k) {
				int curr = sum[k][j] ^ sum[k][i - 1];
				ans = max(ans, curr);
				ans = max(ans, query(curr ^ total));
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}